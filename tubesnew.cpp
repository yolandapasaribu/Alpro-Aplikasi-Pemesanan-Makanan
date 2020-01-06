#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

//pembuka
void titik(){
    cout << "........................................................................."<<endl;
	}
void samadengan(){
    cout << "========================================================================"<<endl;
	}
void strip (){
    cout << "------------------------------------------------------------------------"<<endl;
	}
void spasi (){
    cout << "\n";
	}
void judul(){
    cout << "::::::::::::::::::::: SELAMAT DATANG DI APLIKASI ::::::::::::::::::::::::" <<endl;
    cout << ":::::::::::::::::::::: YUH MADANG! NYONG KENCOT :::::::::::::::::::::::::" <<endl;
	}

int fungsi_total(int porsi, int harga){
	int total=porsi*harga;
	
	return total;
}




//Fungsi sorting_harga(daftar_menu,harga_menu,panjangArray, Mode Ascending / Descending )
void sorting_harga(string menu[],int harga[],int panjangArray,int mode){
	int tmp; //Untuk variabel pertukaran data
	string tmp_string;

	if(mode == 0){ //mode 0, berarti Ascending / cari yang murah
		for(int c=0; c<panjangArray; c++){ //cek semua array
			for(int i=0; i<panjangArray-1; i++){ //perulangan-nya diulang sampai nilai array terakhir KEDUA.
				if(harga[i] > harga[i+1]){ //ngebandingin nilai array saat INI dengan array BERIKUT-nya
					tmp = harga[i];
					harga[i]	= harga[i+1];
					harga[i+1] = tmp;

					tmp_string= menu[i];
					menu[i]	   = menu[i+1];
					menu[i+1]  = tmp_string;
				}
			}
		}
		//Proses sorting selesai.
		cout << "                        DAFTAR MENU TERMURAH                             \n";
		spasi();


	}else if(mode > 0){ //mode 1 atau mode > 0, berarti Descending / sort dari yang mahal
		for(int c=1; c<panjangArray; c++){
			for(int i=0; i<panjangArray-1; i++){
				if(harga[i] < harga[i+1]){
					tmp = harga[i];
					harga[i]	= harga[i+1];
					harga[i+1] = tmp;
					tmp_string= menu[i];
					menu[i]	   = menu[i+1];
					menu[i+1]  = tmp_string;
				}
			}
		}
		//Proses Sort selesai
		cout << "                        DAFTAR MENU TERMAHAL                             \n";
		spasi();
	}

	//Menampilkan data yang telah disort
	for(int c=0; c<10; c++){
		cout<<(c+1)<<". "<<menu[c]<<"Rp "<<harga[c]<<"\n";
	}
}

//Fungsi cari_menu(kata yang dicari, daftar_menu, harga_menu, panjangArray)
void cari_menu(string cari, string menu[],int harga[],int panjangArray){
	size_t penghitung; //size_t itu dari <string.h>
	int nomor=0; //ini cuman untuk keperluan nomor aja pas output.
	for(int i=0;i<panjangArray;i++){
		penghitung = menu[i].find(cari); //Nah ini nyari teks nya
		if(penghitung == 0){ //Kalau ada kata yang cocok dari depan, nilainya 1
			nomor++;
			cout<<nomor<<". "<<menu[i]<<" : "<<harga[i]<<"\n"; //menampilkan pencarian, ini didalam perulangan for
		} //else, penghitung == 1874xxx angkanya gk jelas cuy
	}
	//jika nomor masih bernilai 0, berarti gak ada data yang cocok
	if(nomor == 0){
		spasi();
		cout<<"Mohon maaf menu "<<cari<<" tidak tersedia"<<endl;
	}
}




int main()
{
    // variabel
    string nama_pemesan, cari;
    int no_meja,paket,kode,porsi, jumlah, banyak,bayar,harga,kategori,total;

    //array menu 1

    string menu_custom[26] = {"Nasi Putih\t\t","Nasi Goreng\t\t","Nasi Uduk\t\t","Nasi Rames\t\t","Bubur Ayam\t\t","Soto Ayam\t\t","Soto Makassar\t","Soto Betawi\t\t","Soto Lamongan\t","Gulai Ayam\t\t","Gulai Kambing\t","Mie Goreng\t\t","Ayam Goreng/Bakar\t","Lele Goreng/Bakar \t","Teh Hangat\t\t","Es Teh\t\t","Jeruk Hangat\t\t","Es Jeruk\t\t","Susu Soda\t\t","Jus Alpukat\t\t","Jus Mangga\t\t", "Jus Sirsak\t\t", "Kopi Panas\t\t", "Boba Milk\t\t", "Es Buah\t\t", "Es Teler\t\t"};
	int harga_custom[26] = {4000,12000,10000,8000,12000,12000,15000,15000,15000,15000,20000,12000,15000,15000,3000,5000,4000,6000,8000,10000,10000,10000,3000,8000,12000,12000};
    string menu_pagi[15] = {"Nasi Putih\t\t","Nasi Goreng\t\t", "Nasi Uduk\t\t","Nasi Rames\t\t", "Bubur Ayam Spesial\t\t", "Soto Ayam\t\t", "Soto Lamongan\t\t", "Teh Hangat\t\t", "Es Teh\t\t","Jeruk Hangat\t\t","Es Jeruk\t\t", "Jus Alpukat\t\t", "Jus Mangga\t\t", "Jus Sirsak\t\t", "Kopi Panas\t\t"};
    int harga_pagi[15]  = {4000,12000,10000,8000,12000,12000,15000,3000,5000,4000,6000,10000,10000,10000,3000};
    string menu_siang [19] = {"Nasi Putih\t\t", "Indomie Goreng\t", "Nasi Rames\t\t", "Lele Goreng/Bakar\t", "Udang Goreng\t\t", "Gurameh Bakar/Goreng\t", "Gulai Ayam\t\t", "Sop Ayam\t\t", "Soto Lamongan\t", "Soto Betawi\t\t", "Soto Makassar\t", "Gulai Bebek\t\t", "Teh Hangat\t\t", "Es Teh\t\t" ,"Jeruk Hangat\t\t", "Es Jeruk\t\t", "Kopi\t\t\t", "Susu\t\t\t", "Aneka Jus\t\t"};
    int harga_siang [19] = {4000,5000,6000,12000,13000,18000,14000,12000,10000,10000,15000,15000,4000,4000,4000,4000,4000,4000,10000};
    string menu_malam [18] = {"Nasi Putih\t\t", "Nasi Goreng\t\t", "Indomie Goreng\t", "Indomie Kuah\t\t", "Ayam Goreng/Bakar\t\t", "Bebek Goreng\t\t", "Lele Goreng\t\t", "Gurameh Goreng/Bakar\t\t", "Soto Lamongan\t", "Soto Betawi\t\t", "Soto Makassar\t\t", "Teh Hangat\t\t", "Es Teh\t\t" ,"Jeruk Hangat\t\t", "Es Jeruk\t\t", "Kopi\t\t", "Susu\t", "Aneka Jus\t\t"};
    int harga_malam [18] = {4000,12000,5000,6000,15000,16000,15000,18000,10000,10000,15000,4000,4000,4000,4000,4000,4000,10000};
    //panggil fungsi
    titik();
    judul();
    titik();
    spasi();


    cout << " Masukkan Nama Pemesan : " ;
    cin >> nama_pemesan;
    cout << " Masukkan No. Meja : " ;
    cin >> no_meja;
    spasi();


    //tampil paket makanan dan minuman
    samadengan();
    cout << "                     MENU MAKANAN DAN MINUMAN                         " <<endl;
    samadengan ();
    cout << "  1. Custom" <<endl;
    cout << "  2. Paket Makan Pagi " <<endl;
    cout << "  3. Paket Makan Siang " <<endl;
    cout << "  4. Paket Makan Malam" <<endl;

    //input paket
    spasi();
    cout << " Masukan Pilihan Paket : ";
    cin >> paket;
    spasi();

    //list menu
    switch(paket){
        //========================================================================================================
        case 1:
        //kategori
             kategori:
             samadengan();
             cout << "                            C U S T O M                         " <<endl;
             strip();
             cout << " 1. Menu Harga Termurah" <<endl;
             cout << " 2. Menu Harga Temahal" <<endl;
             cout << " 3. Cari Menu Makanan & Minuman" <<endl;
             cout << " 4. Pesan Makanan & Minuman "<<endl;
             spasi();
             //========================================================================================================
             cout << " Tampilkan Kategori Menu : ";
             cin >> kategori;
             strip();
             //========================================================================================================
             switch(kategori){
             	case 1:
             		sorting_harga(menu_custom,harga_custom,26,0);
             		spasi();
                    getch();
             		goto kategori;
					break;
					//========================================================================================================

				case 2:
					sorting_harga(menu_custom,harga_custom,26,1);
					getch();
             		goto kategori;
					break;
					//========================================================================================================
				case 3:
					cout<<"Cari Menu Makanan & Minuman : ";
					while(cari.length() == 0){
						getline(cin,cari);
					}
					cari_menu(cari,menu_custom,harga_custom,26);
					getch();
             		goto kategori;
					break;
					//========================================================================================================
				case 4 :
					cout << " MAKANAN : " <<endl;
             		cout<<" 1. Nasi Putih\t \t Rp.4000  "; cout<<"\t 8.  Soto Betawi\tRp.15000\n";
             		cout<<" 2. Nasi Goreng\t \t Rp.12000  "; cout<<"\t 9.  Soto Lamongan\tRp.15000\n";
			        cout<<" 3. Nasi Uduk\t \t Rp.10000  "; cout<<"\t 10. Gulai Ayam\t \tRp.15000\n";
			        cout<<" 4. Nasi Rames\t \t Rp.8000  "; cout<<"\t 11. Gulai Kambing\tRp.20000\n";
			        cout<<" 5. Bubur Ayam Spesial\t Rp.12000  "; cout<<"\t 12. Mie Goreng\t\tRp.12000\n";
			        cout<<" 6. Soto Ayam\t\t Rp.12000  "; cout<<"\t 13. Ayam Goreng/Bakar\tRp.15000\n";
			        cout<<" 7. Soto Makassar\t Rp.15000  "; cout<<"\t 14. Lele Goreng/Bakar\tRp.15000\n";
			        spasi();
			        cout << " MINUMAN : " << endl;
			        cout<<" 15. Teh Hangat\t\tRp.3000  "; cout<<"\t 21. Jus Mangga\t\tRp.10000\n";
			        cout<<" 16. Es Teh \t\tRp.5000  "; cout<<"\t 22. Jus Sirsak\t\tRp.10000\n";
			        cout<<" 17. Jeruk Hangat \tRp.4000  "; cout<<"\t 23. Kopi Panas\t\tRp.3000\n";
			        cout<<" 18. Es Jeruk\t \tRp.6000  "; cout<<"\t 24. Boba Milk Tea\tRp.8000\n";
			        cout<<" 19. Susu Soda \t\tRp.8000  "; cout<<"\t 25. Es Buah\t\tRp.12000\n";
			        cout<<" 20. Jus Alpukat \tRp.10000  "; cout<<"\t 26. Es teler\t\tRp.12000\n";
			        samadengan ();
					//====================================PROSES PEMESANAN=====================================================
					cout <<" Jumlah Menu Yang Akan Dipesan : ";
			        cin >> banyak;
			        samadengan();
			        bayar=0;
			        for(jumlah=1;jumlah<=banyak;jumlah++){

			                cout<<"Masukkan Kode Menu Yang Akan Dipesan : ";
			                cin>>kode;
			                spasi();
			                //MENU CUSTOM
			                switch(kode){
			                    case 1:
			                        cout<<"  Nasi Putih\n";
			                        cout<<"  Harga : Rp. 4000\n";
			                        cout<<"  Porsi : ";
			                        cin>>porsi;
			                        harga=4000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 2:
			                        cout<<"  Nasi Goreng\n";
			                        cout<<"  Harga : Rp. 12000\n";
			                        cout<<"  Porsi : ";
			                        cin>>porsi;
			                        harga=12000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 3:
			                        cout << " Nasi Uduk\n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 4:
			                        cout << " Nasi Rames\n";
			                        cout << " Harga : Rp. 8000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=8000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 5:
			                        cout << " Bubur Ayam Spesial\n";
			                        cout << " Harga : Rp. 12000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=12000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 6:
			                        cout << " Soto Ayam\n";
			                        cout << " Harga : Rp. 12000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=12000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 7:
			                        cout << " Soto Makassar\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 8:
			                        cout << " Soto Betawi\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 9:
			                        cout << " Soto Lamongan\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 10:
			                        cout << " Gulai Ayam\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 11:
			                        cout << " Gulai Kambing \n";
			                        cout << " Harga : Rp. 20000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=20000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);

			                    case 12:
			                        cout << " Mie Goreng \n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 13:
			                        cout << " Ayam Goreng/Bakar\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 14:
			                        cout << " Lele Goreng/Bakar\n";
			                        cout << " Harga : Rp. 15000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=15000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 15:
			                        cout << " Teh Hangat\n";
			                        cout << " Harga : Rp. 3000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=3000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 16:
			                        cout << " Es Teh\n";
			                        cout << " Harga : Rp. 5000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=5000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 17:
			                        cout << " Jeruk Hangat\n";
			                        cout << " Harga : Rp. 4000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=4000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 18:
			                        cout << " Es Jeruk\n";
			                        cout << " Harga : Rp. 6000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=6000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 19:
			                        cout << " Susu Soda\n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 20:
			                        cout << " Jus Alpakat\n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 21:
			                        cout << " Jus Mangga\n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 22:
			                        cout << " Jus Sirsak\n";
			                        cout << " Harga : Rp. 10000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=10000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 23:
			                        cout << " Kopi Panas\n";
			                        cout << " Harga : Rp. 3000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=3000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 24:
			                        cout << " Boba Milk\n";
			                        cout << " Harga : Rp. 8000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=8000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;
			                    case 25:
			                        cout << " Es Buah\n";
			                        cout << " Harga : Rp. 12000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=12000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    case 26:
			                        cout << " Es Teler\n";
			                        cout << " Harga : Rp. 12000\n";
			                        cout << " Porsi : ";
			                        cin >>porsi;
			                        harga=12000;
			                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
			                    break;

			                    default:
			                        cout<<"Maaf menu tidak tersedia";
			                    }
			        //=================================== MENGHITUNG TOTAL PEMBAYARAN ========================================================
			        cout<<"\n";
			        bayar=bayar+fungsi_total(porsi,harga);
			        samadengan();
			        }
			         cout<<"  Total Bayar = Rp. "<<bayar<<endl;

			         break;
					 }
			default :
			titik();
			cout<<"                  Mohon Maaf Menu Tidak Tersedia                           "<<endl;
			titik();
			break;

            case 2:
                 //kategori
             kategori_pagi:
             samadengan();
             cout << "                            MAKAN PAGI                         " <<endl;
             strip();
             cout << " 1. Menu Harga Termurah" <<endl;
             cout << " 2. Menu Harga Temahal" <<endl;
             cout << " 3. Cari Menu Makanan & Minuman" <<endl;
             cout << " 4. Pesan Makanan & Minuman "<<endl;
             spasi();
             //========================================================================================================
             cout << " Tampilkan Kategori Menu : ";
             cin >> kategori;
             strip();
             //========================================================================================================
             switch(kategori){
             	case 1:
             		sorting_harga(menu_pagi,harga_pagi,15,0);
             		spasi();
                    getch();
             		goto kategori_pagi;
					break;
					//========================================================================================================

				case 2:
					sorting_harga(menu_pagi,harga_pagi,15,1);
					getch();
             		goto kategori_pagi;
					break;
					//========================================================================================================
				case 3:
					cout<<"Cari Menu Makanan & Minuman : ";
					while(cari.length() == 0){
						getline(cin,cari);
					}
					cari_menu(cari,menu_pagi,harga_pagi,15);
					getch();
             		goto kategori_pagi;
					break;
                case 4:
                    samadengan();
        cout << "                            PAKET MENU MAKAN PAGI                        " <<endl;
        samadengan();
        cout << " MAKANAN : " <<endl;
        cout<<" 1. Nasi Putih\t\tRp.4000  "<<endl;
		cout<<" 2. Nasi Goreng\t\tRp.12000  "<<endl;
		cout<<" 3. Nasi Uduk\t\tRp.10000  "<<endl;
		cout<<" 4. Nasi Rames\t\tRp.8000  "<<endl;
		cout<<" 5. Bubur Ayam Spesial\tRp.12000  "<<endl;
		cout<<" 6. Soto Ayam\t\tRp.12000  "<<endl;
		cout<<" 7. Soto Lamongan\tRp.15000  "<<endl;
		spasi();
		 cout << "MINUMAN : " << endl;
        cout<<" 8. Teh Hangat\t  Rp.3000  "; cout<<"\t 13. Jus Mangga\tRp.10000\n";
        cout<<" 9. Es Teh \t  Rp.5000  "; cout<<"\t 14. Jus Sirsak\tRp.10000\n";
        cout<<" 10. Jeruk Hangat Rp.4000  "; cout<<"\t 15. Kopi Panas\tRp.3000\n";
        cout<<" 11. Es Jeruk\t  Rp.6000  "<<endl;
        cout<<" 12. Jus Alpukat  Rp.10000  "<<endl;
		samadengan ();
		 //====================================PROSES PEMESANAN=====================================================
        cout <<" Jumlah Menu Yang Akan Dipesan : ";
        cin >> banyak;
        bayar=0;
        for(jumlah=1;jumlah<=banyak;jumlah++){
                samadengan();
                cout<<"Masukkan Kode Menu Yang Akan Dipesan : ";
                cin>>kode;
                spasi();
                //MENU CUSTOM
                switch(kode){
                    case 1:
                        cout<<"  Nasi Putih\n";
                        cout<<"  Harga : Rp. 4000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=4000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 2:
                        cout<<"  Nasi Goreng\n";
                        cout<<"  Harga : Rp. 12000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=12000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 3:
                        cout<<"  Nasi Uduk\n";
                        cout<<"  Harga : Rp. 10000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=10000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 4:
                        cout<<"  Nasi Rames\n";
                        cout<<"  Harga : Rp. 8000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=8000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 5:
                        cout<<"  Bubur Ayam Spesial\n";
                        cout<<"  Harga : Rp. 12000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=12000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 6:
                        cout<<"  Soto Ayam\n";
                        cout<<"  Harga : Rp. 12000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=12000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 7:
                        cout<<"  Soto Lamongan\n";
                        cout<<"  Harga : Rp. 15000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=15000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 8:
                        cout<<"  Teh Hangat\n";
                        cout<<"  Harga : Rp. 3000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=3000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 9:
                        cout<<"  Es Teh\n";
                        cout<<"  Harga : Rp. 5000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=5000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 10:
                        cout<<"  Jeruk Hangat\n";
                        cout<<"  Harga : Rp. 4000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=4000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 11:
                        cout<<"  Es Jeruk\n";
                        cout<<"  Harga : Rp. 6000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=6000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 12:
                        cout<<"  Jus Alpukat\n";
                        cout<<"  Harga : Rp. 10000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=10000;
                       cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 13:
                        cout<<"  Jus Mangga\n";
                        cout<<"  Harga : Rp. 10000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=10000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 14:
                        cout<<"  Jus Sirsak\n";
                        cout<<"  Harga : Rp. 10000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=10000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    case 15:
                        cout<<"  Kopi Panas\n";
                        cout<<"  Harga : Rp. 3000\n";
                        cout<<"  Porsi : ";
                        cin>>porsi;
                        harga=3000;
                        cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                    break;
                    }
        //=================================== MENGHITUNG TOTAL PEMBAYARAN ========================================================
        cout<<"\n";
        bayar=bayar+fungsi_total(porsi,harga);
        samadengan();
        		}
        cout<<"  Total Bayar = Rp. "<<bayar<<endl;
             
		break;
		
		default :
			titik();
			cout<<"                  Mohon Maaf Menu Tidak Tersedia                           "<<endl;
			titik();
		break;
	}
		break;

    case 3:
         kategori_siang:
             samadengan();
             cout << "                            MAKAN SIANG                         " <<endl;
             strip();
             cout << " 1. Menu Harga Termurah" <<endl;
             cout << " 2. Menu Harga Temahal" <<endl;
             cout << " 3. Cari Menu Makanan & Minuman" <<endl;
             cout << " 4. Pesan Makanan & Minuman "<<endl;
             spasi();
             //========================================================================================================
             cout << " Tampilkan Kategori Menu : ";
             cin >> kategori;
             strip();
             //========================================================================================================
             switch(kategori){
             	case 1:
             		sorting_harga(menu_siang,harga_siang,19,0);
             		spasi();
                    getch();
             		goto kategori_siang;
					break;
					//========================================================================================================

				case 2:
					sorting_harga(menu_siang,harga_siang,19,1);
					getch();
             		goto kategori_siang;
					break;
					//========================================================================================================
				case 3:
					cout<<"Cari Menu Makanan & Minuman : ";
					while(cari.length() == 0){
						getline(cin,cari);
					}
					cari_menu(cari,menu_siang,harga_siang,19);
					getch();
             		goto kategori_siang;
					break;
                case 4:
                    samadengan();
                    cout << "                            PAKET MENU MAKAN SIANG                        " <<endl;
                    samadengan();
                         cout<< " MAKANAN : " <<endl;
                         cout<<" 1. Nasi Putih\t \t \tRp.4000  "; cout<<"\t 11. Soto Makassar\t Rp.15000\n";
                         cout<<" 2. Indomie Goreng\t \tRp.5000"; cout<<"\t\t 12. Gulai Bebek\t Rp.15000\n";
                         cout<<" 3. Nasi Rames\t \t \tRp.6000 \n";
                         cout<<" 4. Lele Goreng/Bakar\t \tRp.12000  \n";
                         cout<<" 5. Udang Goreng\t \tRp.13000  \n";
                         cout<<" 6. Gurameh Bakar/Goreng\tRp.18000  \n";
                         cout<<" 7. Gulai Ayam\t \t\tRp.14000  \n";
                         cout<<" 8. Sop Ayam\t \t\tRp.12000  \n";
                         cout<<" 9. Soto Lamongan\t \tRp.10000  \n";
                         cout<<"10. Soto Betawi\t\t\tRp.10000 \n";
                         spasi();
                         cout<<"MINUMAN : " << endl;
                         cout<<" 13. Teh Hangat\t  Rp.4000  "; cout<<" \t19. Aneka Jus\t  Rp.10000\n ";
                         cout<<"14. Es Teh\t  Rp.4000  \n";
                         cout<<" 15. Jeruk Hangat Rp.4000  \n";
                         cout<<" 16. Es Jeruk\t  Rp.4000  \n";
                         cout<<" 17. Kopi\t  Rp.4000  \n";
                         cout<<" 18. Susu\t  Rp.4000  \n";

                         samadengan ();
                    //==========================================PROSES PEMESANAN===========================================
                    cout <<" Jumlah Menu Yang Akan Dipesan : ";
                    cin >> banyak;
                    bayar=0;
                    for(jumlah=1;jumlah<=banyak;jumlah++){
                            samadengan();
                            cout<<"Masukkan Kode Menu Yang Akan Dipesan : ";
                            cin>>kode;
                            spasi();
                            //MENU CUSTOM
                            switch(kode){
                                case 1:
                                    cout<<"  Nasi Putih\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 2:
                                    cout<<"  Indomie Goreng\n";
                                    cout<<"  Harga : Rp. 5000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=5000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 3:
                                    cout<<"  Nasi Rames\n";
                                    cout<<"  Harga : Rp. 6000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=6000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 4:
                                    cout<<"  Lele Goreng/Bakar\n";
                                    cout<<"  Harga : Rp. 12000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=12000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 5:
                                    cout<<"  Udang Goreng\n";
                                    cout<<"  Harga : Rp. 13000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=13000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 6:
                                    cout<<"  Gurameh Bakar/Goreng\n";
                                    cout<<"  Harga : Rp. 18000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=18000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 7:
                                    cout<<"  Gulai Ayam\n";
                                    cout<<"  Harga : Rp. 14000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=14000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 8:
                                    cout<<"  Sop Ayam\n";
                                    cout<<"  Harga : Rp. 12000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=12000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 9:
                                    cout<<"  Soto Lamongan\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 10:
                                    cout<<"  Soto Betawi\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 11:
                                    cout<<"  Soto Makassar\n";
                                    cout<<"  Harga : Rp. 15000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=15000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 12:
                                    cout<<"  Gulai Bebek\n";
                                    cout<<"  Harga : Rp. 15000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=15000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 13:
                                    cout<<"  Teh Hangat\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 14:
                                    cout<<"  Es Teh\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 15:
                                    cout<<"  Jeruk Hangat\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 16:
                                    cout<<"  Es Jeruk\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                 case 17:
                                    cout<<"  Kopi\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                   cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                 case 18:
                                    cout<<"  Susu\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                 case 19:
                                    cout<<"  Aneka Jus\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;  }
                    //=================================== MENGHITUNG TOTAL PEMBAYARAN ========================================================
                    cout<<"\n";
                    bayar=bayar+fungsi_total(porsi,harga);
                    samadengan();
                    }
                    cout<<"  Total Bayar = Rp. "<<bayar<<endl;

                    break;
            default :
			titik();
			cout<<"                  Mohon Maaf Menu Tidak Tersedia                           "<<endl;
			titik();
			break;
		}
			break;
            case 4 :
                kategori_malam:
                     samadengan();
                     cout << "                            PAKET MENU MAKAN MALAM                        " <<endl;
                     strip();
                     cout << " 1. Menu Harga Termurah" <<endl;
                     cout << " 2. Menu Harga Temahal" <<endl;
                     cout << " 3. Cari Menu Makanan & Minuman" <<endl;
                     cout << " 4. Pesan Makanan & Minuman "<<endl;
                     spasi();
                     //========================================================================================================
                     cout << " Tampilkan Kategori Menu : ";
                     cin >> kategori;
                     strip();
                     //========================================================================================================
                     switch(kategori){
                        case 1:
                            sorting_harga(menu_malam,harga_malam,18,0);
                            spasi();
                            getch();
                            goto kategori_malam;
                            break;
                            //========================================================================================================

                        case 2:
                            sorting_harga(menu_malam,harga_malam,18,1);
                            getch();
                            goto kategori_malam;
                            break;
                            //========================================================================================================
                        case 3:
                            cout<<"Cari Menu Makanan & Minuman : ";
                            while(cari.length() == 0){
                                getline(cin,cari);
                            }
                            cari_menu(cari,menu_malam,harga_malam,18);
                            getch();
                            goto kategori_malam;
                            break;
                        case 4:
                    samadengan();
                    cout << "                            PAKET MENU MAKAN MALAM                        " <<endl;
                    samadengan();
                         cout<< " MAKANAN : " <<endl;
                         cout<<" 1. Nasi Putih\t \t \tRp.4000  "; cout<<"\t 11. Soto Makassar\t Rp.15000\n";
                         cout<<" 2. Nasi Goreng\t \t \tRp.12000 \n";
                         cout<<" 3. Indomie Goreng\t \tRp.5000 \n";
                         cout<<" 4. Indomie Kuah\t \tRp.6000  \n";
                         cout<<" 5. Ayam Goreng/Bakar\t \tRp.15000  \n";
                         cout<<" 6. Bebek Goreng\t \tRp.16000  \n";
                         cout<<" 7. Lele Goreng\t \t\tRp.15000  \n";
                         cout<<" 8. Gurameh Goreng/Bakar\tRp.18000  \n";
                         cout<<" 9. Soto Lamongan\t \tRp.10000  \n";
                         cout<<"10. Soto Betawi\t\t\tRp.10000 \n";
                         spasi();
                         cout<<"MINUMAN : " << endl;
                         cout<<" 12. Teh Hangat\t  Rp.4000  "; cout<<" \t18. Aneka Jus\t  Rp.10000\n ";
                         cout<<"13. Es Teh\t  Rp.4000  \n";
                         cout<<" 14. Jeruk Hangat Rp.4000  \n";
                         cout<<" 15. Es Jeruk\t  Rp.4000  \n";
                         cout<<" 16. Kopi\t  Rp.4000  \n";
                         cout<<" 17. Susu\t  Rp.4000  \n";

                         samadengan ();
                    //==========================================PROSES PEMESANAN===========================================
                    cout <<" Jumlah Menu Yang Akan Dipesan : ";
                    cin >> banyak;
                    bayar=0;
                    for(jumlah=1;jumlah<=banyak;jumlah++){
                            samadengan();
                            cout<<"Masukkan Kode Menu Yang Akan Dipesan : ";
                            cin>>kode;
                            spasi();
                            //MENU CUSTOM
                            switch(kode){
                                case 1:
                                    cout<<"  Nasi Putih\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 2:
                                    cout<<"  Nasi Goreng\n";
                                    cout<<"  Harga : Rp. 12000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=12000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 3:
                                    cout<<"  Indomie Goreng\n";
                                    cout<<"  Harga : Rp. 5000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=5000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 4:
                                    cout<<"  Indomie Kuah\n";
                                    cout<<"  Harga : Rp. 6000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=6000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 5:
                                    cout<<"  Ayam Goreng/Bakar\n";
                                    cout<<"  Harga : Rp. 15000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=15000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 6:
                                    cout<<"  Bebek Goreng\n";
                                    cout<<"  Harga : Rp. 16000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=16000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 7:
                                    cout<<"  Lele Goreng\n";
                                    cout<<"  Harga : Rp. 15000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=15000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 8:
                                    cout<<"  Gurameh Goreng/Bakar\n";
                                    cout<<"  Harga : Rp. 18000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=18000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 9:
                                    cout<<"  Soto Lamongan\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 10:
                                    cout<<"  Soto Betawi\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 11:
                                    cout<<"  Soto Makassar\n";
                                    cout<<"  Harga : Rp. 15000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=15000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 12:
                                    cout<<"  Teh Hangat\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 13:
                                    cout<<"  Es Teh\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 14:
                                    cout<<"  Jeruk Hangat\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                case 15:
                                    cout<<"  Es Jeruk\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                 case 16:
                                    cout<<"  Kopi\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                 case 17:
                                    cout<<"  Susu\n";
                                    cout<<"  Harga : Rp. 4000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=4000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;
                                 case 18:
                                    cout<<"  Aneka Jus\n";
                                    cout<<"  Harga : Rp. 10000\n";
                                    cout<<"  Porsi : ";
                                    cin>>porsi;
                                    harga=10000;
                                    cout<<"  Total Harga = Rp. "<<fungsi_total(porsi,harga);
                                break;  }
                    //=================================== MENGHITUNG TOTAL PEMBAYARAN ========================================================
                    cout<<"\n";
                    bayar=bayar+total;
                    samadengan();
                    }
                    cout<<"  Total Bayar = Rp. "<<bayar<<endl;

                    break;
             
            default :
			titik();
			cout<<"                  Mohon Maaf Menu Tidak Tersedia                           "<<endl;
			titik();
            break;
		
		}

        getch();
	}

    return 0;
}

