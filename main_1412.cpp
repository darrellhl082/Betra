#include <iostream>
#include <conio.h> // Untuk Getch()
#include <vector> // Untuk Tipe Data vector
using namespace std;

// Tipe Data Vector -> Next Level Array, bisa search di google
vector<string> rute_terpilih; // vector biasa
vector<vector<string>> deskripsi_rute_terpilih; //vector 2 dimensi
vector<vector<string>> opsi_rute_terpilih;


//Tolong ditambahkan data pada vector semua rute dan deskripsi rute.
vector<vector<string>> semua_rute = {{"1-2", "1", "2"}, {"1-3", "4", "5"}};
// Semua rute, isinya semua rute perjalanan dan nomor perjalanannya, tambahkan data sebelum "}" terakhir. Formatnya = {"lokasi awal dan tujuanm misal 1 itu cibiru, 2 itu setiabudi, jadi tulis 1-2, sesaui index array list lokasi di bawah ditambah 1 angka, jadi kalo mau setiabudi-ujung berung tulisnya 2-4", "nomor perjalanannya sesuai sama deskripsi rute, bebas mau ada berapa", "6", "7"}


vector<vector<vector<string>>> deskripsi_rute = {{ {"1"},  {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Cicaheum-Ledeng", "Ledeng"}, {"100"} ,{"4000"}}, { {"2"},  {"3"},  {"Angkot, Angkot, dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum","Cicaheum-Ciroyom", "Ciroyom", "Ciroyom-Lembang", "Lembang"},{"155"}, {"5000"} }};// vector 3 dimensi
// Deskripsi rute, tambah data sebelum '}' terakhir, formatnya {{"nomor rute, mulai lagi dari 3"}, {"Jumlah kendaraan, berapa kali ganti"}, {Jurusannya, index 0,2,4 dst adalah nama trayeknya, index 1,3,5,dst adalah trayek tsb dengan tujuan ke-"}, {"Durasi dalam menit"}, {"tarif"}}. semua pake string.  

// Deklarasi Variabel
float kode_perjalanan;
int awal, akhir, pilihan, pilihan_panduan, pilihan_opsi_rute, kode_rute_terpilih;
char konfirmasi;
string nama_pelanggan, rute, data, pesan;
bool punya_tiket;
// Array
string lokasi[] = {"Cibiru", "Setiabudi", "Stasiun bandung", "Ujung Berung"}; //Array List Lokasi, kalo mau ditambah lagi juga boleh

// Prototipe Fungsi
void tampilMenuUtama();
void tentangBetra();
void panduanInformasiPerjalanan();

int main()
{   
    punya_tiket = false;
    pilihan_opsi_rute = 0;
    pilihan = 0;
    pilihan_panduan = 0;
    do{
        menu_utama:
        tampilMenuUtama(); //Memanggil fungsi TampilMenuUtama
        cout << "Silahkan pilih menu mana yang ingin anda gunakan: ";
        cin >> pilihan;
        cin.ignore();
        if(pilihan==1){
            rute_terpilih.clear();
            deskripsi_rute_terpilih.clear();
            opsi_rute_terpilih.clear();
            memilih_lokasi:
            system("cls");
            cout << "===Daftar Lokasi Tersedia===" << endl;
            for(int i = 0; i <4; i++){
                cout << i+1 << ". " << lokasi[i] << endl;
            }
            cout << endl;
            cout << "===Mulai Perjalanan===" << endl;
            cout << "Pilih Lokasi Awal: ";
            cin >> awal;
            cout << "Pilih Lokasi Tujuan: ";
            cin >> akhir;
            cout << "Yakin? (y/n): ";
            cin >> konfirmasi;
            if (konfirmasi == 'n'){
                goto memilih_lokasi;
            }
            rute = to_string(awal) + '-' + to_string(akhir);
            system("cls");
            for(int i = 0; i < semua_rute.size(); i++){
                if (semua_rute[i][0] == rute){
                    for (int j = 0; j < semua_rute[i].size();j++){
                        rute_terpilih.push_back(semua_rute[i][j]);
                    }
                }
            }
            cout << "Berikut informasi untuk  perjalanan dengan rute " << lokasi[awal-1] << '-' << lokasi[akhir-1] << endl;
            cout << "Terdapat " << (rute_terpilih.size()-1) << " opsi rute: " << endl;
            for (int i = 0; i < rute_terpilih.size()-1; i++){
                deskripsi_rute_terpilih = deskripsi_rute[stoi(rute_terpilih[i+1])-1];
                cout << "=====================================================================================" << endl;
                cout << "\t\t\t\t\tOpsi Ke-" << i+1 << endl;
                cout << "=====================================================================================" << endl;
                cout << "Perjalanan dengan kode R" << deskripsi_rute_terpilih[0][0] << endl;
                cout << "Akan menggunakan " << deskripsi_rute_terpilih[1][0] << " kendaraan berbeda dengan jenis moda yaitu " << deskripsi_rute_terpilih[1][0] << endl;
                for(int k = 0; k < stoi(deskripsi_rute_terpilih[1][0]); k++){
                    cout << "\t" << k+1 << ". Jurusan " << deskripsi_rute_terpilih[3][k*2] << " tujuan " << deskripsi_rute_terpilih[3][k*2+1] << endl;
                }
                cout << "Waktu Perjalanan: " << stoi(deskripsi_rute_terpilih[4][0])/60 << " Jam " << stoi(deskripsi_rute_terpilih[4][0])%60 << " Menit" << endl;
                cout << "Tarif: Rp" << deskripsi_rute_terpilih[5][0] << endl; 
                cout << endl;  
            }
            memilih_opsi:
            cout << "Pilih Opsi Rute: ";
            cin >> pilihan_opsi_rute;
            cout << "Yakin? (y/n): ";
            cin >> konfirmasi;
            if (konfirmasi == 'n'){
                goto memilih_opsi;
            }
            system("cls");
            opsi_rute_terpilih = deskripsi_rute[stoi(rute_terpilih[pilihan_opsi_rute])-1];
            cout << "Anda memilih perjalanan dengan kode R" << opsi_rute_terpilih[0][0] << " dengan tarif Rp" << opsi_rute_terpilih[5][0] << endl;
            cout << endl;
            cout << "Lakukan Pembayaran" << endl;
            cout << "Konfirmasi Pembayaran (y/n): ";
            cin >> konfirmasi;
            if (konfirmasi == 'n'){
                goto menu_utama;
            } else if (konfirmasi == 'y'){
                system("cls");
                cout << "Pembayaran Berhasil!" << endl;
                punya_tiket = true;
            }
            getch();
            system("cls");
        }else if(pilihan==2){
            system("cls");
            if (punya_tiket){
                cout << "Tiket Saya: " << endl;
                cout << "Kode perjalanan R" << rute_terpilih[pilihan_opsi_rute] << " dengan rute " << lokasi[awal-1] << '-' << lokasi[akhir-1] << endl;
            } else {
                cout << "Belum memesan perjalanan" << endl;
            }
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls"); 
        }else if(pilihan==3){
            system("cls");
            panduanInformasiPerjalanan(); //Memanggil Fungsi
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==4){
            system("cls");
            cout << "Riwayat Perjalanan" << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==5){
            system("cls");
            cout << "Pelaporan Keamanan" << endl;
            cout << "Nama Anda: "<<endl;
            getline(cin, nama_pelanggan);
            cout << "Kode perjalanan: "<< endl;
            cin >> kode_perjalanan;
            cout << "Tulis Laporan Anda: " << endl;
            cin.ignore();
            getline(cin, pesan);
            cout << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==6){
            system("cls");
            tentangBetra(); //Memanggil Fungsi
            cout << "tekan apapun untuk melanjutkan\n";
            getch();
            system("cls");
        }else if(pilihan==7){
            system("cls");
            cout << "Terimakasih telah menggunakan aplikasi betra :)" << endl;
        } else {
            system("cls");
            cout << "Pilihan tidak valid, silakan ulangi" << endl;
        }
    }while(pilihan!=7);
    cin.get();
    return 0;
}


// Penjabaran Fungsi
void tampilMenuUtama(){
    cout << "================================\n";
    cout << "SELAMAT DATANG DI APLIKASI BETRA\n";
    cout << "================================\n";
    cout << "MENU BETRA\n";
    cout << endl;
    cout << "1. Mulai perjalanan\n";
    cout << "2. Tiket Saya\n";
    cout << "3. Panduan dan Informasi Perjalanan\n";
    cout << "4. Riwayat Perjalanan\n";
    cout << "5. Laporan Kemanan\n";
    cout << "6. Tentang Betra\n";
    cout << "7. Keluar\n";

}
void tentangBetra(){
    cout << "Tentang Betra" << endl << endl;
    cout << "Betra adalah sebuah nama yang disingkat dari nama kota bandung dan bahasa sunda dan sansakerta.\nyaitu eka berarti satu, yatra berarti perjalanan. \nBetra menyajikan pengalaman perjalanan yang menyeluruh.\nDengan fitur rute, manajemen, dan pembayaran yang terpadu,\nBetra memastikan setiap perjalanan menjadi lebih efisien dan tak terlupakan.\n\nprogram ini dibuat oleh Darrel, Rifqi, Chandra  " << endl;
    cout << "Betra dibuat untuk mengintegrasikan semua angkutan umum menjadi satu dalam sebuah aplikasi\n";
    cout << "mempermudah masyarakat untuk berpergian, dan mengurangi kemacetan karena berhenti sembarangan\n";
}

void panduanInformasiPerjalanan(){
    label_panduan:
    cout << "Panduan dan Informasi Perjalanan" << endl;
    cout << "1. Panduan\n";
    cout << "2. Informasi Perjalanan\n";
    cout << "3. Keluar\n";
    cin >> pilihan_panduan;       
    if(pilihan_panduan == 1){
        system("cls");
        cout << "PANDUAN PEMAKAIAN APLIKASI BETRA\n";
        cout << "1. Sambungkan ke koneksi internet\n";
        cout << "2. buka aplikasi betra\n";
        cout << "3. jika anda ingin memulai pejalanan pilih menu no 1\n";
        cout << "4. jika anda ingin melihat tiket anda pilih menu no 2\n";
        cout << "5. jika anda ingin butuh panduan dan informasi pilih menu no 3\n";
        cout << "6. jika anda ingin melihat riwayat perjalanan anda ada di menu no 4\n";
        cout << "7. jika ada kendala atau masalah laporkan di menu no 5\n";
        cout << "8. jika anda ingin membayar di menu no 6\n";
        cout << "9. ada beberapa informasi di aplikasi betra di menu no 7\n";
        cout << "Kembali? (y/n)";
        cin >> konfirmasi;
        if (konfirmasi  == 'y'){
            goto label_panduan;
        }
        getch();
        system("cls");
    }else if(pilihan_panduan == 2){
        system("cls");
        cout << "tekan apapun untuk melanjutkan\n";
        getch();
        system("cls");
    }else if(pilihan_panduan == 3){
        system("cls");
    }else{
        system("cls");
        cout << "kode yang anda inputkan tidak ada silahkan ulangi";
        goto label_panduan;
    }
}