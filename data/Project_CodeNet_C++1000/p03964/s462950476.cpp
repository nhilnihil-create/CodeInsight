#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 1000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll GCD(ll a,ll b){
    if(a < b)return GCD(b,a);
    ll r = INF;
    while(r){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
 ll N;cin >> N;
 ll ans = 0;
 ll g = 0;
 ll m1,m2;
 vector<ll> A(N),B(N);
 set<ll> S;
 for(ll i = 0;i < N;i++){
     cin >> A[i] >> B[i];
     if(i == 0){
         m1 = A[i];m2 = B[i];
     }else{
         for(ll j = max(m1/A[i],m2 / B[i]);;j++){
             if(A[i] * j >= m1 && B[i] * j >= m2){
                 m1 = A[i] * j;
                 m2 = B[i] * j;
                 break;
             }
         }
     }
 }
 cout << m1 + m2 << endl;
}
