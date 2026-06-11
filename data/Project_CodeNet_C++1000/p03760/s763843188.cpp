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
  string s, t; cin >> s >> t;
  rep(i,t.size()) cout << s[i] << t[i];
  if (s.size()-t.size()==1){
    cout << s[s.size()-1] << endl;
  }
  

  // cout << fixed << setprecision(6);
  return 0;
}

