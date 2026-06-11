#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string S; cin >> S;
  map<char, int> d;
  rep(i,S.size()) d[S[i]]++;
  
  bool NS = !((d['S']==0) ^ (d['N']==0));
  bool WE = !((d['E']==0) ^ (d['W']==0));
  
  if (NS && WE) cout << "Yes" << endl;
  else cout << "No" << endl;


  // cout << fixed << setprecision(6);
  return 0;
}

