#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    string s; cin>>s;
    string div[4]={"dream","dreamer","erase","eraser"};
    reverse(s.begin(),s.end());
    rep(i,4) reverse(div[i].begin(),div[i].end());
    bool ok=true;
    for(int i=0;i<s.size();){
        bool ok2=false;
        rep(j,4){
            string d=div[j];
            if(s.substr(i,d.size())==d){
                ok2=true;
                i+=d.size();
            }
        }
        if(!ok2){
            ok=false;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}