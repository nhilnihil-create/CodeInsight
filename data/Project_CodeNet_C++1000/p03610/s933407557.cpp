#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    string s;
    cin >> s;
    string t="";
    for(int i=0;i<s.size();i++){
        if(i%2==0)t.push_back(s[i]);
    }
    cout << t << endl;
}

int main(){
  solve();
  return 0;
}
