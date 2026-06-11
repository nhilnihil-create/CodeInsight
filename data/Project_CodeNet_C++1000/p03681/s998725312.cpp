#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll F(ll n){
ll A = 2, B = 1;
    while(A <= n){
    B *= A;B %= 1000000007;
    A++;
    }
return B;
}

int main() {
ll N, M;cin >> N >> M;

if(abs(N - M) >= 2)cout << 0;

if(N == M)cout << (F(N)*F(M)*2)%1000000007;

if(abs(N - M) == 1)cout << (F(N)*F(M))%1000000007;

}
