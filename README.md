# Distance Vector Simulator

### Oleh

Kelompok 
13515035 - Oktavianus Handika
13515065 - Felix Limanta
13515089 - Vincent Hendryanto Halim

## Petunjuk Penggunaan Program

Jalankan `make` di terminal pada direktori program di mana terdapat Makefile.

Masukkan input berturut-turut berupa jumlah node, jumlah edge, hubungan suatu node dengan node lainnya sebanyak jumlah edgenya, banyak skenario pengiriman informasi.



## Implementasi Program

Program dibuat dengan struktur data kelas graf dengan sejumlah node tertentu untuk merepresentasikan jaringan. 

Ketika program menerima input awal berupa banyak node dalam graf, akan dibentuk kelas `Graph` dengan konstruktor `Graph(v)` dimana v = banyak node yang ingin dibentuk pada graf. Setiap node akan memiliki *routing table* yang berisi jarak node asal dengan node lainnya dan NextHop yang berisi node yang dituju satu langkah setelahnya untuk mencapai node yang dituju. Setiap node dalam graf akan di-*assign* sebuah *value* untuk jarak ke node lainnya dengan suatu konstanta (*distance* = ∞) dan NextHop-nya -1 yang berarti node tidak terhubung dengan node yang dituju. Sedangkan pada node dengan tujuan node itu sendiri di-*assign* nilai *distance* = 0 dan NextHop-nya adalah node itu sendiri. Ketika program menerima input edge yang menghubungkan 2 node berbeda, pada *routing table* node yang bersangkutan, input node akan masuk pada prosedur `addEdge()` berisi node asal dengan node tujuan dan *edge weight*-nya (bernilai 1). Dalam prosedur ini, akan dilakukan *update* nilai *distance* antara satu node dengan node lain yang bersangkutan, NextHop-nya berupa node tujuan, dan banyak edge yang telah dibentuk pada suatu graf.

Setiap kali menerima input node asal yang mengirimkan informasi ke suatu node tujuan, akan dilakukan pengiriman pesan node asal ke node tujuan untuk dilakukan *update* *routing table* pada node tujuan. Pengiriman pesan antar node dalam program dilakukan dengan memanggil prosedur `sendInfo()` dengan input 2 node (node asal dan node tujuan). Jika berdasarkan *routing table* atau informasi dari node asal terdapat jarak yang lebih pendek dari node tujuan ke suatu node lain, akan dilakukan *update* pada jarak (*distance*)  dan NextHop dari node yang dituju pada suatu node. Jika jarak suatu node dengan node lainnya terdapat 2 jalur dengan jarak sama namun dengan NextHop berbeda, maka diambil NextHop dengan angka yang terkecil.



## Pembagian Tugas

13515035 - Input/Output, Readme
13515065 - Algoritma
13515089 - Makefile, Readme



## Jawaban Pertanyaan

Pada *protocol distance-vector*, penentuan *routing* terdekat ditentukan pada jarak dan arah terdekat (*Hop Count*). *Hop Count* di sini berarti banyak *device/router* yang harus dilalui untuk mencapai *router* tujuan. Setiap *router* akan mengirimkan *routing table* ke *router* terdekat untuk melakukan pengalamatan pada paket data yang akan dikirim tanpa mengetahui bagaimana *router* tersebut terkoneksi. *Protocol distance-vector* biasanya digunakan pada jaringan yang tidak terlalu luas. *Routing* dengan *distance-vector* memiliki konvergensi yang lebih lambat dibandingkan dengan *link state*

Pada *protocol link state*, penggunaan *protocol* ini bertujuan untuk menciptakan kembali topologi pada suatu jaringan. *Protocol* ini akan melacak status dan jenis koneksi pada masing-masing *link* dan menghasilkan metriks yang dihitung berdasarkan informasi mengenai *link* tersebut dan faktor-faktor lainnya seperti *bandwidth*, panjang *path* ke suatu *router*, *delay*, dan sebagainya,  sehingga *protocol* ini lebih menitikberatkan pada perhitungan biaya metriksnya (*metric cost*). *Routing* dengan *link state* memiliki konvergensi yang lebih cepat dibandingkan dengan *distance-vector*. Dalam *routing* ini, setiap *router* akan menggunakan algoritma Dijkstra untuk menghitung route terbaik dalam setiap tujuannya. 

*Routing protocol distance-vector* lebih baik digunakan pada ukuran jaringan yang lebih kecil dan *link* memiliki kecepatan yang tidak terlalu jauh antara satu *link* dengan *link* lainnya pada suatu jaringan. Sedangkan *routing protocol link state* lebih baik digunakan pada ukuran jaringan yang lebih luas.

Pada implementasinya saat ini, *link state* lebih banyak digunakan untuk aplikasi berskala besar, karena jaringan pada aplikasi relatif kompleks dan biasanya untuk melakukan *routing* diperlukan data *metric cost* pada suatu *link*.  Selain itu, biasanya dibutuhkan *resources memory* yang lebih besar dan *hardware* yang lebih mendukung (memiliki performansi lebih bagus). Namun untuk aplikasi yang lebih kecil/sederhana, lebih banyak digunakan *distance-vector* karena lebih mudah dirancang dan diimplementasi dan cenderung digunakan pada jaringan yang kecil daripada *link state* yang cenderung digunakan pada jaringan yang lebih kompleks, rumit, dan membutuhkan *resources* lebih.