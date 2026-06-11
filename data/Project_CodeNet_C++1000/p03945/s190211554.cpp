#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    string s; cin >> s;
    int n=s.size();
    int ans=0;
    char now=s[0];
    rep2(i,n){
        if(s[i]!=now){
            now=s[i];
            ans++;
        }
    }
    cout << ans << endl;
}