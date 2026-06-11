#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

ll gcd(ll N, ll M){

if(N%M == 0)return M;

else return gcd(M, N%M);

}

ll F(ll N, ll M){
return N/gcd(N, M)*M;
}

int main() {
ll N, Ans = 1;cin >> N;
vector<ll> T(N);

rep(i, 0, N)cin >> T[i];

rep(i, 0, N){

Ans = F(T[i], Ans);

}

cout << Ans;

}