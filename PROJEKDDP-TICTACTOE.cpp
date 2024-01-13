#include<iostream>
using namespace std;

struct Pemain {
    string nama;//untuk inputan nama dari pemain 
    char simbol;//menandakan simbol x dan o
    int menang;//jumlah kemenngan dari tiap pemain
};

char papan[3][3] = {{'1', '2', '3'},
                   {'4', '5', '6'},
                   {'7', '8', '9'}};//- char papan[3][3]: Matriks 3x3 yang merepresentasikan papan permainan Tic Tac Toe.


int hitung = 1;//- int hitung: Variabel untuk menghitung jumlah langkah yang telah dilakukan.



void resetPapan() {
    // Mengatur atau membuat ulang papan ke kondisi awal permainan
    papan[0][0] = '1'; papan[0][1] = '2'; papan[0][2] = '3';
    papan[1][0] = '4'; papan[1][1] = '5'; papan[1][2] = '6';
    papan[2][0] = '7'; papan[2][1] = '8'; papan[2][2] = '9';
}// - Fungsi ini digunakan untuk mengatur ulang papan ke kondisi awal permainan.



void tampilkanPapan() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << papan[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}//- Fungsi ini digunakan untuk menampilkan papan permainan ke layar.


bool cekMenang(char pemain) {
    // Untuk Cek baris, kolom, dan diagonal, agar mengetahui kemenangan setiap pemain berasa dari arah mana
    for (int i = 0; i < 3; i++) {
        if ((papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain) ||//baris
            (papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain)) {//kolom
            return true; 
            
        }
    }

    if ((papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain) ||//diagonal1
        (papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain)) {//diagonal2
        return true;
         
    }

    return false;
}//- Fungsi ini digunakan untuk memeriksa apakah pemain dengan simbol tertentu telah menang. Fungsi ini memeriksa baris, kolom, dan diagonal papan.

bool cekSeri() {
    return hitung == 10;//mengecek keserian dalam permainan
}

void lakukanLangkah(Pemain &pemain) {//- Fungsi ini meminta pemain untuk memasukkan langkahnya (angka 1-9), memeriksa kevalidan langkah, 
                                       //dan mengupdate papan permainan.

    int pilihan;
    cout <<"Pemain=>"<<pemain.nama<<endl; 
    cout <<"Pilih angka yang telah tersedia=> 1-9 : ";
    cin >> pilihan;

    // Cek apakah posisi yang dipilih valid
    if (pilihan < 1 || pilihan > 9) {
        cout << "Kamu salah memasukkan angka: " << endl;
        return;
    }

    // Konversi pilihan ke indeks baris dan kolom
    int baris = (pilihan - 1) / 3;
    int kolom = (pilihan - 1) % 3;

    // Cek apakah posisi yang dipilih sudah terisi
    if (papan[baris][kolom] == 'X' || papan[baris][kolom] == 'O') {
        cout << ".Silahkan pilih posisi lain." << endl;
        return;
    }

    // Lakukan langkah
    papan[baris][kolom] = pemain.simbol;
    hitung++;//
}

int main() {
    Pemain pemain1, pemain2;
    pemain1.simbol = 'X';
    pemain2.simbol = 'O';
    
    cout <<"==================================================="<<endl;
	cout <<"||            UNIVERSITAS AHMAD DAHLAN           ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"|| Nama   : La Ode Abdul Rahim Matullah          ||"<<endl;
	cout <<"|| NIM    : 2300018006                           ||"<<endl;
	cout <<"|| Kelas  : A                                    ||"<<endl;
	cout <<"|| Tugas  : DASAR DASAR PEMOGRAMAN               ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"||                S1 INFORMATIKA                 ||"<<endl;
	cout <<"==================================================="<<endl;
	cout <<"||                 SELAMAT DATANG DI             ||"<<endl;
	cout <<"||                  TIC TAC TOE                  ||"<<endl;
	cout <<"==================================================="<<endl;
    
    cout << "Masukkan nama Pemain 1 |X|: ";
    cin >> pemain1.nama;
    
    cout << "Masukkan nama Pemain 2 |O|: ";
    cin >> pemain2.nama;

    char mainLagi;

    do {
        resetPapan(); // Menjalankan fungsi resetPapan() sesudah  memulai permainan
        hitung = 1; 

        cout << "PERMAINAN TIC TAC TOE" << endl;

        do {
            tampilkanPapan();

            if (hitung % 2 == 0) {
                lakukanLangkah(pemain2);
            } else {
                lakukanLangkah(pemain1);
            }

            // Cek untuk menang atau seri
            if (cekMenang(pemain1.simbol)) {
                tampilkanPapan();
                cout << pemain1.nama << " Selamat anda menang!" << endl;
                pemain1.menang++;
                break;
            } else if (cekMenang(pemain2.simbol)) {
                tampilkanPapan();
                cout << pemain2.nama << " Selamat anda menang!" << endl;
                pemain2.menang++;
                break;
            } else if (cekSeri()) {
                tampilkanPapan();
                cout << "Permainan seri!" << endl;
                break;
            }

        } while (true);

        cout << "Apakah kamu ingin bermain lagi? (y/n): ";
        cin >> mainLagi;

    } while (mainLagi == 'y' || mainLagi == 'Y');

    cout << "Terima kasih telah bermain!" << endl;
    cout << "==========================================="<<endl;
    cout << "||"<< pemain1.nama << "=> Anda Menang Sebanyak: " << pemain1.menang << " kali. ||" << endl;
    cout << "||"<< pemain2.nama << "=> Anda Menang Sebanyak: " << pemain2.menang << " kali. ||" << endl;
    cout << "==========================================="<<endl;

    return 0;
}
