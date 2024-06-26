#include <iostream>
using namespace std;

struct Tagihan
{
    string namaPelanggan;
    string tanggal;
    int jumlahTagihan;

    Tagihan *next;
    Tagihan *prev;
};

Tagihan *kepala, *bt, *ini, *nwNode, *busek;
int maks = 5;

int hitung () {
    if (kepala == NULL) {
        return 0;
    }
    else
    {
        int banyak = 0;
        ini = kepala;
        while (ini != NULL)
        {
            ini = ini->next;
            banyak++;
        }
        return banyak;
    }
}

bool penuhKah () {
    if (hitung() == maks || hitung() >= maks) {
        return true;
    } else
    {
        return false;
    }
    
}

bool kosongKah () {
    if (hitung() == 0) {
        return true;
    } else
    {
        return false;
    }
    
}

void tambah (string nama, string tanggal, int jumlah) {
    if (penuhKah())
    {
        cout << "Full" << endl;
    }else
    {
        if (kosongKah())
        {
            kepala = new Tagihan;
            kepala->namaPelanggan = nama;
            kepala->tanggal = tanggal;
            kepala->jumlahTagihan = jumlah;
            kepala->prev = NULL;
            kepala->next = NULL;
            bt = kepala;
        }else
        {
            nwNode = new Tagihan;
            nwNode->namaPelanggan = nama;
            nwNode->tanggal = tanggal;
            nwNode->jumlahTagihan = jumlah;
            nwNode->prev = bt;
            bt -> next = nwNode;
            nwNode->next = NULL;
            bt = nwNode;
        }  
    } 
}

void hapus() {
    while (ini != NULL)
    {
    busek = bt;
    bt = bt->prev;
    bt->next = NULL;
    delete busek;
    }
}

int cetak () {
    if (kepala == NULL) {
        cout << "stack kosong" << endl;
    }
    else
    {
        cout << "Data Pelanggan" << endl;
        ini = bt;
        while (ini != NULL)
        {
            cout << "Nama Pelanggan: " << ini->namaPelanggan << " - " << ini->tanggal << " - Rp." << ini->jumlahTagihan << endl;
            cout << endl;
            ini = ini->prev; 
        }
    }
}

void peek(int posisi) {
    if (kepala == NULL) {
        cout << "Data kosong" << endl;
    }else
    {
        int nomor = 1;
        ini = bt;
        while (nomor < posisi)
        {
            ini = ini->prev;
            nomor++;
        }
        cout << "data ke- " << posisi << "Nama Pelanggan: " << ini->namaPelanggan << " - " << ini->tanggal << " - Rp." << ini->jumlahTagihan << endl;
        cout << endl;
    }
    
}
void ubah(string namaPelanggan, string tanggal, int harga, int posisi) {
    if (kosongKah()) {
        cout << "Data kosong" << endl;
    }else
    {
        int nomor = 1;
        ini = bt;
        while (nomor < posisi)
        {
            ini = ini->prev;
            nomor++;
        }
        ini->namaPelanggan = namaPelanggan;
        ini->tanggal = tanggal;
        ini->jumlahTagihan = harga;
    }
    
}

void destroy () {
    ini = kepala;
    while (ini != NULL)
    {
        busek = ini;
        kepala = kepala->next;
        delete busek;
        ini = ini-> next;
    }
    
}

int main () {
    tambah("Bagus", "2 Maret 2010", 50000);
    tambah("Eko", "11 Mei 2021", 20000);
    hapus();

    // destroy();
    tambah("wijayanto", "17 Agustus 1945", 500000);
    tambah("Bagus Eko", "26 Februari 2011", 5500);
    peek(2);
    ubah("wiwi", "2 november 1999", 50000, 3);
    cetak();
} 