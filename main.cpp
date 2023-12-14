#include <iostream>
#include <conio.h> // Untuk Getch()
#include <vector> // Untuk Tipe Data vector
using namespace std;

// Tipe Data Vector -> Next Level Array
vector<string> kode_rute;
vector<vector<string>> semua_rute = {{"1-2", "1", "2"}, {"1-3", "4", "5"}};
vector<vector<string>> kode_rute2;
vector<vector<vector<string>>> deskripsi_rute = {{{"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Cicaheum-Ledeng", "Ledeng"}, {"100"} ,{"4000"}}, {{"3"},  {"Angkot, Angkot, dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum","Cicaheum-Ciroyom", "Ciroyom", "Ciroyom-Lembang", "Lembang"},{"155"}, {"5000"} }};

// Deklarasi Variabel
float kode_perjalanan;
int awal, akhir, pilihan, pilihan_panduan;
char kembali;
string nama_pelanggan, rute, data, pesan;

// Array
string lokasi[] = {"Cibiru", "Setiabudi", "Stasiun bandung", "ujung berung"}; //Array List Lokasi

// Prototipe Fungsi
void tampilMenuUtama();
void tentangBetra();
void panduanInformasiPerjalanan();

int main()
{   
    pilihan = 0;
    pilihan_panduan = 0;
    do{
        tampilMenuUtama(); //Memanggil fungsi TampilMenuUtama
        cout << "Silahkan pilih menu mana yang ingin anda gunakan: ";
        cin >> pilihan;
        cin.ignore();
        if(pilihan==1){
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
            rute = to_string(awal) + '-' + to_string(akhir);
            system("cls");
            for(int i = 0; i < semua_rute.size(); i++){
                if (semua_rute[i][0] == rute){
                    for (int j = 0; j < semua_rute[i].size();j++){
                        kode_rute.push_back(semua_rute[i][j]);
                    }
                }
            }
            cout << "Berikut informasi untuk kode perjalanan " << rute << " dengan rute " << lokasi[awal-1] << '-' << lokasi[akhir-1] << endl;
            cout << "Terdapat " << (kode_rute.size()-1) << " opsi rute: " << endl;
            for (int i = 0; i < kode_rute.size()-1; i++){
                kode_rute2 = deskripsi_rute[stoi(kode_rute[i+1])-1];
                cout << "=====================================================================================" << endl;
                cout << "\t\t\t\t\tOpsi Ke-" << i+1 << endl;
                cout << "=====================================================================================" << endl;
                cout << "Akan menggunakan " << kode_rute2[0][0] << " kendaraan berbeda dengan jenis moda yaitu " << kode_rute2[1][0] << endl;
                for(int k = 0; k < stoi(kode_rute2[0][0]); k++){
                    cout << "\t" << k+1 << ". Jurusan " << kode_rute2[2][k*2] << " tujuan " << kode_rute2[2][k*2+1] << endl;
                }
                cout << "Waktu Perjalanan: " << stoi(kode_rute2[3][0])/60 << " Jam " << stoi(kode_rute2[3][0])%60 << " Menit" << endl;
                cout << "Tarif: Rp" << kode_rute2[4][0] << endl; 
                cout << endl;  
            }
            getch();
            system("cls");
        }else if(pilihan==2){
            system("cls");
            cout << "Tiket Saya" << endl;
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
    label_kembali:
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
        cout << "tekan apapun untuk melanjutkan\n";
        cout << "Kembali? (y/n)";
        cin >> kembali;
        if (kembali  == 'y'){
            goto label_kembali;
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
        goto label_kembali;
    }
}