#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  
  int add = a;

  vector<int> amari(105);
  while(1){
    int r = a%b;
    if(amari.at(r)) break;
    amari.at(r)++;
    if(r==c){cout<<"YES"; return 0;}
    a+=add;
    a%=b;
    //cout << a << " ";
  }

  cout << "NO";
}