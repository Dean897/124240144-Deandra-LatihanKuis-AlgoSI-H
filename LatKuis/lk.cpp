#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct buku
{
    int id_bk;
    char judul[50];
    char pengarang[50];
    int stok;
};
buku bk[100];

void tambah_buku(int x)
{
    FILE *buku;
    buku = fopen("data.dat", "a");
    if (buku == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        exit(1);
    }
    for (int i = 0; i < x; i++)
    {
        cout << "ID Buku :";
        cin >> bk[i].id_bk;
        cin.ignore(); // Supaya bisa menggunakan spasi
        cout << "Judul :";
        cin.getline(bk[i].judul, 50);
        cout << "Pengarang :";
        cin.getline(bk[i].pengarang, 50);
        cout << "Stok :";
        cin >> bk[i].stok;
        fprintf(buku, "%d|%s|%s|%d\n", bk[i].id_bk, bk[i].judul, bk[i].pengarang, bk[i].stok);
    }
    fclose(buku);
}

void tampilkan_bk()
{
    FILE *buku;
    buku = fopen("data.dat", "r");
    if (buku == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    struct buku buku_baca[100];
    int baris = 0;
    char buffer[150];
    while (fgets(buffer, sizeof(buffer), buku))
    {
        sscanf(buffer, "%d|%49[^|]|%49[^|]|%d", &buku_baca[baris].id_bk, buku_baca[baris].judul, buku_baca[baris].pengarang, &buku_baca[baris].stok);
        baris++;
    }
    fclose(buku);

    // Bubble sort
    for (int i = 0; i < baris - 1; i++)
    {
        for (int j = 0; j < baris - i - 1; j++)
        {
            if (buku_baca[j].id_bk > buku_baca[j + 1].id_bk)
            {
                swap(buku_baca[j], buku_baca[j + 1]);
            }
        }
    }

    // Menampilkan data dalam bentuk tabel
    cout << left << setw(5) << "ID" << setw(30) << "Judul" << setw(20) << "Pengarang" << setw(5) << "Stok" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < baris; i++)
    {
        cout << left << setw(5) << buku_baca[i].id_bk << setw(30) << buku_baca[i].judul << setw(20) << buku_baca[i].pengarang << setw(5) << buku_baca[i].stok << endl;
    }
}

void cari_bk()
{
    FILE *buku;
    buku = fopen("data.dat", "r");
    if (buku == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    struct buku buku_baca[100];
    int baris = 0;
    char buffer[150];
    while (fgets(buffer, sizeof(buffer), buku))
    {
        sscanf(buffer, "%d|%49[^|]|%49[^|]|%d", &buku_baca[baris].id_bk, buku_baca[baris].judul, buku_baca[baris].pengarang, &buku_baca[baris].stok);
        baris++;
    }
    fclose(buku);

    int cari;
    cout << "Masukkan ID Buku yang dicari :";
    cin >> cari;
    bool found = false;
    for (int i = 0; i < baris; i++)
    {
        if (cari == buku_baca[i].id_bk)
        {
            found = true;
            cout << "Data ditemukan" << endl;
            cout << left << setw(5) << "ID" << setw(30) << "Judul" << setw(20) << "Pengarang" << setw(5) << "Stok" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << left << setw(5) << buku_baca[i].id_bk << setw(30) << buku_baca[i].judul << setw(20) << buku_baca[i].pengarang << setw(5) << buku_baca[i].stok << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Buku tidak ditemukan" << endl;
    }
}

void hapus_bk()
{
    FILE *buku;
    buku = fopen("data.dat", "r");
    if (buku == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    struct buku buku_baca[100];
    int baris = 0;
    char buffer[150];
    while (fgets(buffer, sizeof(buffer), buku))
    {
        sscanf(buffer, "%d|%49[^|]|%49[^|]|%d", &buku_baca[baris].id_bk, buku_baca[baris].judul, buku_baca[baris].pengarang, &buku_baca[baris].stok);
        baris++;
    }
    fclose(buku);

    int hapus;
    cout << "Masukkan ID Buku yang ingin dihapus :";
    cin >> hapus;
    for (int i = 0; i < baris; i++)
    {
        if (hapus == buku_baca[i].id_bk)
        {
            cout << "Data ditemukan" << endl;
            cout << " Buku berhasil dihapus" << endl;
            for (int j = i; j < baris - 1; j++)
            {
                buku_baca[j] = buku_baca[j + 1];
            }
            baris--;
            break;
        }
    }

    buku = fopen("data.dat", "w");
    if (buku == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        return;
    }
    for (int i = 0; i < baris; i++)
    {
        fprintf(buku, "%d|%s|%s|%d\n", buku_baca[i].id_bk, buku_baca[i].judul, buku_baca[i].pengarang, buku_baca[i].stok);
    }
    fclose(buku);
}

int main()
{
    int pw = 144;
    string userNm = "deden";
    string Nma;
    int pass;
    int x;
    int pilih;
    string jwb;

    // Menu Login
    cout << "=============================" << endl;
    cout << "Selamat Datang di Perpustakaan IF" << endl;
    cout << "Masukkan Username :";
    cin >> Nma;
    cout << "Masukkan Password :";
    cin >> pass;
    cout << endl;

    do
    {
        if (Nma == userNm && pass == pw)
        {
            cout << "Login Berhasil" << endl;
            break;
        }
        else
        {
            cout << "Username atau Password salah" << endl;
            cout << "Masukkan Username :";
            cin >> Nma;
            cout << "Masukkan Password :";
            cin >> pass;
            cout << endl;
        }
    } while (Nma != userNm || pass != pw);

    do
    {
        // Menu
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Buku" << endl;
        cout << "3. Cari Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih :";
        cin >> pilih;
        cout << endl;
        // Pilihan
        switch (pilih)
        {
        case 1:
            cout << "Mau nambah brp buku :";
            cin >> x;
            tambah_buku(x);
            cout << endl;
            break;
        case 2:
            tampilkan_bk();
            cout << endl;
            break;
        case 3:
            cari_bk();
            cout << endl;
            break;
        case 4:
            hapus_bk();
            cout << endl;
            break;
        case 5:
            cout << "Terima Kasih" << endl;
            cout << endl;
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }

        if (pilih == 5)
        {
            break;
        }

        cout << "Apakah anda ingin melanjutkan ? (y/n) :";
        cin >> jwb;
    } while (jwb == "y" || jwb == "Y");

    return 0;
}
