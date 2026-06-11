#include <iostream>
using namespace std;
int main(){
  long long k;cin>>k;
  if(k == 0){
    cout << 2 << endl;
    cout << "0 1" << endl;
  }else if(k == 1){
    cout << 2 << endl;
    cout << "0 2" << endl;
  }else if(k < 51){
    cout << k << endl;
    for(int i = 1; k >= i; i++){
      cout << i;
      if(i != k)cout << " ";
    }
    cout << endl;
    return 0;
  }else{
    long long syoki = k/50;
    long long wari = 50- (k % 50);
    cout << 50 << endl;
    for(int i = 1; 50 >= i; i++){
      long long kekka = syoki+i;
      if(wari != 0){
        kekka += (wari >= i ? -1:-0);
      }
      cout << kekka;
      if(i != k)cout << " ";
    }
    cout << endl;
    
  }
}