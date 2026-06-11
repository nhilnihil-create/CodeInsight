#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int n; cin >> n;
  string s,t; cin >> s >> t;

  for(int i=0;i<n;i++){
    string str = s;
    for(int j=n-i;j<n;j++){
      str+=t.at(j);
    }

    bool ok = true;

    for(int j=0;j<n;j++){
      if(t.at(j)!=str.at(j+i)) ok= false;
    }

    if(ok){
      cout << n+i << endl;
      return 0;
    }
  }

  cout << 2*n << endl;
}