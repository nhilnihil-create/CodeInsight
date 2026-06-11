#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define REP2(i, n) for (LL i = 1; i <= (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,k,r,x,y,z,ans=0,ans2=0;
string s,S,t;
bool flag=false; 
int main() {
ios_base::sync_with_stdio(false);
cin >> n >> m;
vector<vector<char>> A(n,vector<char>(n));
vector<vector<char>> B(m,vector<char>(m));
REP(i,n){
  REP(j,n){
    cin>>A[i][j];
  }
}
REP(i,m){
  REP(j,m){
    cin>>B[i][j];
  }
}
for(int i=0;i<n-m+1;i++){
  for(int j=0;j<n-m+1;j++){
    for(int k=0;k<m;k++){
      for(int l=0;l<m;l++){
          if(A[i+k][j+l]!=B[k][l]){
            flag=true;
              break;   
             }
          if(k==m-1){
            cout << "Yes"<<endl;
            return 0;
          }
             }
      if(flag){
      flag=false;
      break;
          } 
         }
        }
      }
     cout <<"No"<<endl;
}
