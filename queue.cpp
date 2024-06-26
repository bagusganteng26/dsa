#include <iostream>
using namespace std;

int maks = 5, depan = 0, blkg = 0;
string antrian[5];

bool fullKah()
{
  if( blkg == maks ){
    return true;
  }else{
    return false;
  }
}


bool kosongKah()
{
  if( blkg == 0 ){
    return true;
  }else{
    return false;
  }
}


void tambah(string data){

  if( fullKah() ){
    cout << "Antrian full bos!!" << endl;
  }else{

    if( kosongKah() ){
      antrian[0] = data;
      depan++;
      blkg++;
    }else{
      antrian[blkg] = data;
      blkg++;
    }
  }

}

void hapus(){
  if( kosongKah() ){
    cout << "Antrian kosong guys!!" << endl;
  }else{
    for( int i = 0; i < blkg; i++ ){
      antrian[i] = antrian[i+1];
    }
    blkg--;
  }
}

int hitung()
{

  if( kosongKah() ){
    return 0;
  }else if( fullKah() ){
    return maks;
  }else{
    return blkg;
  }

}

void destroyArray(){
  if( kosongKah() ){
    cout << "Antrian kosong haha" << endl;
  }else{
    for( int i = 0; i < maks; i++ ){
      
      if( blkg > 1 ){
        antrian[blkg - 1] = "";
        blkg--;
      }else if( blkg == 1 ){
        antrian[blkg - 1] = "";
        blkg = 0;
        depan = 0;
      }

    }
  }
}

void cetak()
{
  cout << "Banyak antrian : " << hitung() << endl;
  cout << "Data antrian : " << endl;
  if( kosongKah() ){
    cout << "Antrian kosong gaes" << endl;
  }else{
    for( int i = 0; i < maks; i++ ){
      if( antrian[i] != "" ){
        cout << i+1 << ". " << antrian[i] << endl;
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
hapus();
tambah ("Caca");
tambah ("Dewi");
tambah ("Elga");
tambah ("Fauzi");


cetak();

}