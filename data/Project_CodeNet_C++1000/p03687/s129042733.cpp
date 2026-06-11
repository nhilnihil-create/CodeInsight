#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    cin>>s;
    
    int n=s.size();
    int ans=INF;

    for(char x='a';x<='z';x++){
        bool ok=false;
        rep(i,n){
            if(s[i]==x) ok=true;
        }
        if(!ok) continue;
        int ma=0,tmp=0;
        rep(i,n){
            if(s[i]==x){
                ma=max(ma,tmp);
                tmp=0;
            }
            else tmp++;
        }
        ma=max(ma,tmp);
        //cout<<x<<" "<<ma<<endl;
        ans=min(ans,ma);
    }

    cout<<ans<<endl;
}
