#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  int amari = 0;
  int k = 1;
  int number = a;
  int check[b];
  rep(i, b) {
    check[i] = 0;
  }
  
  while(ans == 0){
    amari = number % b;
    
    k++;
    number = a * k;
    
    if (amari == c){
      ans = 1;
      break;
    }
    
    else
    {
      check[amari] ++;
    }
    
    if(check[amari] > 1){
      ans = 2;
      break;
    }
  }

  if (ans == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}