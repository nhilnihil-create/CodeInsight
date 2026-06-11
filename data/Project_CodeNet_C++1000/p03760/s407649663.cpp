#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string s,t;cin>>s>>t;
    int m = s.size();
    int n = t.size();
    rep(i,m){
    cout<<s[i];
    if(i<n)cout<<t[i];
    }
    cout<<endl;
	return 0;
}