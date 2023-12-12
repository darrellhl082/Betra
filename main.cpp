#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;


int main(int argc, char const *argv[])
{   
    int pilihan = 0;
    do{
        
        cout << "================================\n";
        cout << "SELAMAT DATANG DI APLIKASI BETRA\n";
        cout << "================================\n";

        cout << "MENU BETA\n";
        cout << "1. Mulai perjalanan\n";
        cout << "2. Tiket Saya\n";
        cout << "3. Panduan dan Informasi Perjalanan\n";
        cout << "4. Riwayat Perjalanan\n";
        cout << "5. Laporan Kemanan\n";
        cout << "6. Akun Anda\n";
        cout << "7. BetraPay\n";
        cout << "8. Tentang Betra\n";
        cout << "9. Keluar\n";

        cout << "Silahkan pilih menu mana yang ingin anda gunakan: ";
        cin >> pilihan;
   
        if(pilihan==1){
            system("cls");
            cout << "Mulai Perjalanan" << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
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
            cout << "Panduan dan Informasi Perjalanan" << endl;
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
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==6){
            system("cls");
            cout << "Akun Saya" << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==7){
            system("cls");
            cout << "BetraPay" << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==8){
            system("cls");
            cout << "Tentang Betra" << endl;
            cout << "Tekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }else if(pilihan==9){
            system("cls");
            cout << "Terimakasih telah menggunakan aplikasi betra :)" << endl;
        } else {
            system("cls");
            cout << "Pilihan tidak valid, silakan ulangi" << endl;
        }
    }while(pilihan!=9);
    cin.get();
    return 0;
}
