#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    string s;
    cin>>s;

    int n=s.size();
    int ans=INF;
    bool o=true;
    char y=s[0];
    rep(i,n){
        if(s[i]!=y) o=false;
    }

    if(o){
        cout<<0<<endl;
        return 0;
    }

    rep(i,n){
        char x=s[i];
        string t=s;
        int tmp=0;
        while(1){
            tmp++;
            string tt="";
            rep(j,t.size()-1){
                if(t[j]==x || t[j+1]==x) tt+=x;
                else tt+=t[j];
            }
            bool ok=true;
            rep(j,tt.size()){
                if(tt[j]!=x) ok=false;
            }
            if(ok) break;
            t=tt;
        }
        ans=min(ans,tmp);
    }

    cout<<ans<<endl;
}