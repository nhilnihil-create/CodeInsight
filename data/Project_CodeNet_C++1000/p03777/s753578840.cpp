#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin,(x).end()

int main(){
  char a,b;
  cin >> a >> b;
  if(a=='H'){
    if(b=='H'){
      cout << "H" << endl;
    }
    if(b=='D'){
      cout << "D" << endl;
    }
  }
  
  if(a=='D'){
     if(b=='H'){
       cout << "D" << endl;
     }
     if(b=='D'){
       cout << "H" << endl;
     }
  }
}