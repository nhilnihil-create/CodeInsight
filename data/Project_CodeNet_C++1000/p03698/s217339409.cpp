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
  string s; cin >> s;
  set<char> S;
  rep(i,s.size()){
    if (S.count(s[i])==true) {
      cout << "no" << endl;
      return 0;
    }
    else S.insert(s[i]);
  }
  cout << "yes" << endl;
  
  // cout << fixed << setprecision(6);
  return 0;
}
