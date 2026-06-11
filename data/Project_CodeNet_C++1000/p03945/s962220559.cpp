#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main(){
    string s; cin >> s;
    int n = s.size();
    int res = 0;
    rep(i,n-1){
        if(s[i]!=s[i+1]) res++;
    }
    cout << res << endl;
}