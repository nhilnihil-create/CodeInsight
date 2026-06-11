#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
//------------------------------------------//

int main(){
  char C[20];
  rep(i,19){
    cin>>C[i];
    if(C[i]==',') C[i]=' ';
    cout<<C[i];
  }
}