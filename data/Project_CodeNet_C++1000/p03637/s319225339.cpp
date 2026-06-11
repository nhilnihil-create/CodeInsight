#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main() {
ll N, P = 0;;cin >> N;
rep(i, 0, N){
ll a;cin >> a;

if(a%2 == 0 && a%4 != 0)P+=1;
if(a%4 == 0)P+=2;
}

if(N%2 == 0 && P >= N){cout << "Yes";exit(0);}
if(N%2 != 0 && P >= N - 1){cout << "Yes";exit(0);}
cout << "No";
}