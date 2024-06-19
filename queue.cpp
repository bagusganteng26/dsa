#include <iostream>
using namespace std;

int maks = 5, front = 0, back = 0;
string antrianAtm[5];

bool fullKah()
{
  if( back == maks ){
    return true;
  }else{
    return false;
  }
}


bool kosongKah()
{
  if( back == 0 ){
    return true;
  }else{
    return false;
  }
}


void tambah(string data){

  if( fullKah() ){
    cout << "Antrian penuh!!" << endl;
  }else{

    if( kosongKah() ){
      antrianAtm[0] = data;
      front++;
      back++;
    }else{
      antrianAtm[back] = data;
      back++;
    }
  }

}

void hapus(){
  if( kosongKah() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < back; i++ ){
      antrianAtm[i] = antrianAtm[i+1];
    }
    back--;
  }
}

int hitung()
{

  if( kosongKah() ){
    return 0;
  }else if( fullKah() ){
    return maks;
  }else{
    return back;
  }

}

void destroyArray(){
  if( kosongKah() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < maks; i++ ){
      
      if( back > 1 ){
        antrianAtm[back - 1] = "";
        back--;
      }else if( back == 1 ){
        antrianAtm[back - 1] = "";
        back = 0;
        front = 0;
      }

    }
  }
}

void cetak()
{
  cout << "Jumlah data yg ngantri : " << hitung() << "data." << endl;
  cout << "Data Antrian Atm : " << endl;
  if( kosongKah() ){
    cout << "Antrian kosong!!" << endl;
  }else{
    for( int i = 0; i < maks; i++ ){
      if( antrianAtm[i] != "" ){
        cout << i+1 << ". " << antrianAtm[i] << endl;
      }else{
        cout << i+1 << ". (kosong)" << endl;
      }
    }
  }
  cout << "\n" << endl;
}



int main()
{
tambah ("Alex");
tambah ("Budi");
tambah ("Caca");
tambah ("Dewi");
tambah ("Elga");
tambah ("Fauzi");
hapus();


cetak();

}