#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 int N;
 cin>>N;
 vector<int>T(N);
 int cnt=0;
 rep(i,N){
     cin>>T[i];
     cnt+=T[i];
 }
 int M;
 cin>>M;
 vector<int>P(M);
 vector<int>X(M);
 rep(i,M){
     cin>>P[i];
     cin>>X[i];
     cout<<cnt-T[P[i]-1]+X[i]<<endl;
 }
}


