#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
//#define for(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, K, Ans = 0;cin >> N >> K;
map<ll, ll> MAP;

for(int i = 0; i < N; i++){
ll a, b;cin >> a >> b;
MAP[a] += b;
}

for(auto x : MAP){

K -= x.second;
if(K <= 0){Ans = x.first;break;}
}
cout << Ans;
}