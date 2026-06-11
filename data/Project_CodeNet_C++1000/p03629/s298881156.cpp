#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}

////////////////////////////////////////

bool che[26];
int cou;
void init(){
    memset(che,false,sizeof(che));
    cou=0;
}

int main(){
    string s;cin>>s;
    int n=s.size();
    vector<int>v;
    v.pb(n);
    int pos=n-1;
    while(pos>=0){
        if(!che[s[pos]-'a']){
            cou++;
            che[s[pos]-'a']=true;
        }
        if(cou==26){
            init();
            v.pb(pos);
        }
        pos--;
    }
    reverse(v.begin(),v.end());
    string ans;
    
    pos=0;
    for(auto y:v){
        int x=pos;
        init();
        rep(i,x,y-1){
            che[s[i]-'a']=true;
        }
        int t;
        for(t=0;t<=25;t++){
            if(!che[t])break;
        }
        ans+=('a'+t);
        
        while(y<=n-1){
            if(s[y]-'a'==t)break;
            y++;
        }
        pos=y+1;
    }
    cout<<ans<<endl;
    return 0;
}