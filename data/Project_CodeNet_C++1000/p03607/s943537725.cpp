#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N;cin >> N;
map<ll, ll> A;

rep(i, 0, N){

ll a;cin >> a;

if(A[a] == 0)A[a]++;

else A[a]--;

}

ll Ans = 0;

for(auto x : A){

if(x.second == 1)Ans++;

}

cout << Ans;
}
