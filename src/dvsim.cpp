#include <stdio.h>

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
                    next[i][j] = i;
                } else {
                    dist[i][j] = -1;
                    next[i][j] = -1;
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

    void addEdge(int a, int b) {
        a--;
        b--;
        dist[a][b] = 1;
        dist[b][a] = 1;
        next[a][b] = b;
        next[b][a] = a;
        e++;
    }

    void sendInfo(int x, int y) {

    }

    void printGraph() {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                printf("%d %d\n", dist[i][j], next[i][j] + 1);
            }
        }
    }

private:
    int v;
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
    for (int i = 0; i < e; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        g.addEdge(a, b);
    }

    // // Run simulation
    // int n;
    // scanf("%d", &n);
    // for (int i = 0; i < n; ++i) {
    //     int x, y;
    //     scanf("%d %d", &x, &y);
    //     g.sendInfo(x, y);
    // }

    g.printGraph();

    return 0;
}

