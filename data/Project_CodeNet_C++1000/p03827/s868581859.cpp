#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,x=0,ans=0;
    string s;
    cin >> n >> s;
    
    rep(i,n){
        if(s[i]=='I')x+=1;
        else x-=1;
        ans=max(ans,x);
    }
    
    cout << ans;
    
    return 0;
}