#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll a,b,c;
  cin >> a >> b >> c;

  int num = 0;
  ll na,nb,nc;
  for(int i = 0; i < 100; i++){
    if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
      break;
    } else { 
      num++;
      na = b/2 + c/2;
      nb = a/2 + c/2;
      nc = a/2 + b/2;
      a = na;
      b = nb;
      c = nc;
    }
  }

  cout << (num==100 ? -1 : num) << endl;
}

