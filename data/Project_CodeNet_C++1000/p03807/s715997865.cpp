#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,buf;
  cin >> N;

  int Nodd= 0;
  for(int i=0; i<N; i++){
    cin >> buf;
    if(buf%2==1){ Nodd++; }
  }

  string ans= (Nodd%2==0) ? "YES" 
                          : "NO";
  cout << ans << endl;
}