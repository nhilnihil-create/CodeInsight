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

ll func(string s){
  if (s.size()==1) return stoll(s);

  ll tot = stoll(s);
  ll pow2 = 1;
  for (int i=1;i<s.size();i++) {
    tot += func(s.substr(0,i)) + pow2*stoll(s.substr(i));
    pow2*=2;
  }
  
  return tot;
}

int main(){
  string s; cin >> s;
  cout << func(s) << endl;

  return 0;
}

