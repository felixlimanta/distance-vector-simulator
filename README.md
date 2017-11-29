# Distance Vector Simulation

### Kelompok K2-08 - KapanKelarYa
- 13515035 - Oktavianus Handika
- 13515065 - Felix Limanta
- 13515089 - Vincent Hendryanto Halim

## Petunjuk Penggunaan Program

- Jalankan `make` di terminal pada direktori _root_ program ini untuk mengkompilasi program.
- Jalankan perintah `dvsim.exe` untuk mengeksekusi program
	- Sebagai alternatif, jalankan perintah `make run` untuk mengeksekusi program.
- Masukkan input berturut-turut berupa jumlah node, jumlah edge, hubungan suatu node dengan node lainnya sebanyak jumlah edgenya, banyak skenario pengiriman informasi.

## Implementasi Program

Spesifikasi tugas selengkapnya dapat dilihat [pada tautan berikut][1].

Jaringan pada permasalahan dimodelkan dengan sebuah kelas `Graph`.

Ketika program menerima input awal berupa banyak simpul `v` dan banyak sisi `e` dalam jaringan, akan dibentuk objek dari kelas `Graph` dengan jumlah simpul sesuai dengan masukan dan 0 sisi. Kelas `Graph` memiliki 2 matriks bilangan bulat berukuran `v`$\times$`v` untuk merepresentasikan jarak antar simpul (`dist`) dan simpul berikut yang harus dituju (`next`). Matriks `dist` akan diinisalisasi dengan nilai ∞ dan matriks `next` dengan nilai `NUL`, yang berarti simpul asal tidak terhubung dengan simpul tujuan. Jika simpul asal dan tujuan sama, matriks `dist` diinisialisasi dengan 0 dan `next` dengan ID simpul itu sendiri. Proses inisialisasi yang telah dijelaskan tadi dilakukan dalam konstruktor `Graph(v)`, di mana `v` adalah jumlah simpul dalam graf.

Program kemudian akan membaca sisi sejumlah nilai `e` yang telah dibaca sebelumnya. Sisi dibaca sebagai pasangan bilangan ID simpul asal `x` dan ID simpul tujuan `y`. Sisi yang dibaca kemudian ditambahkan pada graf menggunakan _method_ `addEdge(x, y, w)`, di mana `x` dan `y` adalah kedua simpul yang terhubung dan `w` adalah bobot sisi yang menghubungkan (karena graf tidak berbobot dan tidak berarah, nilai `w` secara _default_ bernilai 1). Pada _method_ tersebut, dilakukan _assignment_ nilai `dist[x][y] = 1` dan nilai `next[x][y] = y`. Perlu diperhatikan bahwa graf tak berarah, sehingga penambahan sisi dari `x` ke `y` juga secara otomatis menyebabkan penambahan sisi dari `y` ke `x`.

Selanjutnya program membaca jumlah skenario `n` yang akan dilaksanakan. Untuk setiap skenario, dibaca pasangan bilangan ID simpul asal `x` dan ID simpul tujuan `y`, lalu _method_ `sendInfo(x, y)` dipanggil untuk mengirimkan pesan. Dalam _method_, untuk setiap simpul `i`, akan dicari apakah, jika dari simpul `y`, simpul `i` lebih dekat jika melalui `x`, sama dekatnya, atau lebih jauh. Jika lebih dekat, nilai `dist[y][i]` diperbarui dengan nilai `dist[x][i]` dan nilai `next[y][i]` di-_assign_ dengan `x`. Jika sama dekatnya, akan dipilih nilai `next` dengan ID terkecil, sehingga nilai `dist[y][i]` tidak diperbarui, tetapi nilai `next[y][i]` diganti dengan nilai minimum dari dirinya sendiri dan `x`.

Terakhir, setelah semua skenario dijalankan, nilai kedua matriks dikeluarkan ke layar sesuai format yang diberikan. Perlu diperhatikan bahwa, pada spesifikasi, ID simpul dimulai dari 1, sedangkan ID simpul pada kelas `Graph` dimulai dari 0, sehingga untuk setiap masukan yang dijalankan di atas ID simpul dikurangi 1 terlebih dahulu, sedangkan ID simpul yang dikeluarkan ditambah 1. Nilai ∞ dan `NUL` keduanya dikeluarkan sebagai $-1$.

## Jawaban Pertanyaan

### Apakah perbedaan dari protokol _routing_ _distance-vector_ dan _link state_? Manakah yang​ ​lebih​ ​baik​ ​untuk​ ​digunakan?

Pada protokol _distance-vector_, penentuan _routing_ terdekat ditentukan pada jarak dan arah terdekat (_hop count_). _Hop count_ di sini berarti banyak _device/router_ yang harus dilalui untuk mencapai _router_ tujuan. Eksekusi _routing_ pada protokol ini didasari pada algoritma Bellman-Ford, di mana setiap _router_ mengirimkan _routing table_ ke _router_ terdekat untuk melakukan pengalamatan pada paket data yang akan dikirim tanpa mengetahui bagaimana _router_ tersebut terkoneksi. Protokol _distance-vector_ biasanya digunakan pada jaringan yang tidak terlalu luas. _Routing_ dengan _distance-vector_ memiliki konvergensi yang lebih lambat dibandingkan dengan _link state_.

Pada protokol _link state_, penggunaan protokol ini bertujuan untuk menciptakan kembali topologi pada suatu jaringan. Protokol ini akan melacak status dan jenis koneksi pada masing-masing _link_ dan menghasilkan metrik yang dihitung berdasarkan informasi mengenai _link_ tersebut dan faktor-faktor lainnya, seperti _bandwidth_, panjang _path_ ke suatu _router_, _delay_, dan sebagainya, sehingga _protokol_ ini lebih menitikberatkan pada perhitungan biaya metriksnya (_metric cost_). _Routing_ dengan _link state_ memiliki konvergensi yang lebih cepat dibandingkan dengan _distance-vector_. Dalam _routing_ ini, setiap _router_ akan menggunakan algoritma Dijkstra untuk menghitung route terbaik dalam setiap tujuannya. 

Protokol _routing_ _distance-vector_ lebih baik digunakan pada ukuran jaringan yang lebih kecil dan jarak antar _link_ dalam jaringan tidak terlalu jauh, sedangkan protokol _routing_ _link state_ lebih baik digunakan pada ukuran jaringan yang lebih luas.

### Pada implementasinya saat ini manakah yang lebih banyak digunakan, _distance-vector_​ ​atau _​link​ ​state_?​ ​Kenapa?
Pada implementasinya saat ini, _link state_ lebih banyak digunakan untuk aplikasi berskala besar karena jaringan pada aplikasi relatif kompleks dan biasanya untuk melakukan _routing_ diperlukan data _metric cost_ pada suatu _link_.  Selain itu, biasanya dibutuhkan _resource memory_ yang lebih besar dan perangkat keras yang lebih mendukung (memiliki performansi lebih bagus). Meskipun demikian, untuk aplikasi yang lebih kecil/sederhana, lebih banyak digunakan _distance-vector_ karena lebih mudah dirancang dan diimplementasi.

## Pembagian Tugas

13515035 - Input/Output, Readme
13515065 - Algoritma
13515089 - Makefile, Readme

[Spek]: ./doc/Spesifikasi Tubes 2 - Distance Vector Simulation.pdf