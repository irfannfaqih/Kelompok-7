#include <iostream>
#include <string>
using namespace std;

#define MAX_FILM 5

struct Film
{
    string judul;
    string jadwal;
    int sisaTiket;
};

Film daftarFilm[MAX_FILM] = {
    {"Civil War", "10:00", 100},
    {"Inside Out 2", "13:00", 100},
    {"Ipar adalah Maut ", "16:00", 100},
    {"Jurnal Risa", "19:00", 100},
    {"Despicable Me 4", "21 : 00 ", 100}}

void
tampilkanFilm()
{
    cout << "Daftar Film:\n";
    for (int i = 0; i < MAX_FILM; i++)
    {
        cout << i + 1 << ". " << daftarFilm[i].judul << " - " << daftarFilm[i].jadwal << " - Tiket tersisa: " << daftarFilm[i].sisaTiket << endl;
    }
}
void pesanTiket()
{
    int pilihanFilm, jumlahTiket;
    tampilkanFilm();
    cout << "Pilih film yang ingin dipesan (1-" << MAX_FILM << "): ";
    cin >> pilihanFilm;
    cout << "Masukkan jumlah tiket yang ingin dipesan: ";
    cin >> jumlahTiket;

    if (pilihanFilm < 1 || pilihanFilm > MAX_FILM)
    {
        cout << "Pilihan film tidak tersedia.\n";
    }
    else if (jumlahTiket > daftarFilm[pilihanFilm - 1].sisaTiket)
    {
        cout << "Jumlah tiket tidak mencukupi.\n";
    }
    else
    {
        daftarFilm[pilihanFilm - 1].sisaTiket -= jumlahTiket;
        cout << "Selamat, Tiket berhasil dipesan!\n";
    }
}

void kelolaMenu()
{
    int pilihan;
    do
    {
        cout << "\nSistem Pemesanan Tiket Bioskop\n";
        cout << "1. Tampilkan Daftar Film\n";
        cout << "2. Pesan Tiket\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tampilkanFilm();
            break;
        case 2:
            pesanTiket();
            break;
        case 3:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);
}
int main()
{
    kelolaMenu();
    return 0;
}