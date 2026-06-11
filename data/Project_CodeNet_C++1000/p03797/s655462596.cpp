#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, M;cin >> N >> M;

if(M < 2*N){cout << M/2;exit(0);}

cout << (2*N + M)/4;

}
