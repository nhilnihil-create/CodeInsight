#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    string s,t;
    cin>>s>>t;
    ll ssum[(int)s.size()+1];
    ssum[0]=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')ssum[i+1]=1;
        else ssum[i+1]=2;
        ssum[i+1]+=ssum[i];
    }
    ll tsum[(int)t.size()+1];
    tsum[0]=0;
    for(int i=0;i<t.size();i++){
        if(t[i]=='A')tsum[i+1]=1;
        else tsum[i+1]=2;
        tsum[i+1]+=tsum[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if((ssum[b]-ssum[a-1])%3==(tsum[d]-tsum[c-1])%3){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}