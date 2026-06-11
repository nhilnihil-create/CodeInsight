#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

ll F(ll N, ll a, ll p){
 
    if(a == 0)return 1;
 
    if(a%2 == 0 && a != 0)return (F(N, a/2, p)*F(N, a/2, p))%p;
 
    if(a%2 == 1)return N*F(N, a - 1, p)%p;
 
}

int main() {
ll N , Ans = 0;cin >> N;
bool C = 1;
map<ll, ll> M;

rep(i, 0, N){

  ll a;cin >> a;

  M[a]++;

}
  
//for(auto x : M)cout << x.first << " " << x.second << endl;

if(N%2 != 0){

  if(M[0] == 1){

    for(ll i = 2; i < N; i+=2){

      if(M[i] != 2){C = 0;break;}

    }

  }

  else C = 0;

}

else{

  for(ll i = 1; i < N; i+=2){

    if(M[i] != 2){C = 0;break;}

  }

}

if(C)cout << F(2, N/2, PP);

else cout << 0;

}