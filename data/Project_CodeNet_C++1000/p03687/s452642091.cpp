#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    string s;cin>>s;
    vector<int> cnt(26,0);
    for(int i=0;i<(int)s.size();i++) cnt[(int)(s[i]-'a')]++;
    
    int ans=INF;
    for(int i=0;i<26;i++){
        int m=0;
        int l=0,r=0;
        for(int j=0;j<(int)s.size();j++){
            if(s[j]==(char)('a'+i)||j==(int)s.size()-1){
                l=r;
                r=j;
                m=max(m,max(r-l-(s[l]==s[r]?1:0),0));
            }
        }
        ans=min(ans,m);
    }
    cout<<ans<<endl;
    return 0;
}