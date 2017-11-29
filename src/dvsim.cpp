#include <stdio.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}

class Graph {
public:
    Graph(int v): v(v) {
        dist = new int*[v];
        next = new int*[v];

        for (int i = 0; i < v; ++i) {
            dist[i] = new int[v];
            next[i] = new int[v];

            for (int j = 0; j < v; ++j) {
                if (i == j) {
                    dist[i][j] = 0;
                    next[i][j] = j;
                } else {
                    dist[i][j] = INF;
                    next[i][j] = NUL;
                }
            }
        }
        e = 0;
    }

    ~Graph() {
        for (int i = 0; i < v; ++i) {
            delete dist[i];
            delete next[i];
        }
        delete dist;
        delete next;
    }

    int getNumOfNodes() {
        return v;
    }

    int getNumOfEdges() {
        return e;
    }

    void addEdge(int x, int y, int weight = 1) {
        dist[x][y] = weight;
        dist[y][x] = weight;
        next[x][y] = y;
        next[y][x] = x;
        e++;
    }

    void sendInfo(int x, int y) {
        for (int i = 0; i < v; ++i) {
            int newDist = dist[y][x] + dist[x][i];
            if (newDist < dist[y][i]) {
                dist[y][i] = newDist;
                next[y][i] = x;
            } else if (newDist == dist[y][i]) {
                next[y][i] = min(x, next[y][i]);
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                int outDist = dist[i][j];
                if (outDist == INF)
                    outDist = -1;
                int outNext = next[i][j];
                if (outNext != NUL)
                    outNext++;

                printf("%d %d\n", outDist, outNext);
            }
        }
    }

private:
    const int INF = 1001;
	const int NUL = -1;
    const int v;
    int e;
    int** dist;
    int** next;
};

int main() {
    // Create empty graph
    int v, e;
    scanf("%d %d", &v, &e);
    Graph g(v);

    // Add edges to graph
    while (e--) {
        int a, b;
        scanf("%d %d", &a, &b);
        g.addEdge(--a, --b);
    }

    // Run simulation
    int n;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        g.sendInfo(--x, --y);
    }

    g.printGraph();

    return 0;
}