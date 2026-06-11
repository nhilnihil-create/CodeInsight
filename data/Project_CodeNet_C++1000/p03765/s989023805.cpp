//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;
                                                                                                     
ll MOD=1000000007;                                                                                     
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s,t; cin>>s>>t;
    int q,sn=s.size(),tn=t.size(); cin>>q;
    vector<int> ssum(sn+1,0),tsum(tn+1,0);
    rep(i,sn){
        ssum[i+1]=ssum[i];
        if(s[i]=='A') ssum[i+1]+=2;
        else ssum[i+1]++;
    }
    rep(i,tn){
        tsum[i+1]=tsum[i];
        if(t[i]=='A') tsum[i+1]+=2;
        else tsum[i+1]++;
    }
    rep(i,q){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int snum=ssum[b]-ssum[a-1];
        int tnum=tsum[d]-tsum[c-1];
        if(abs(snum-tnum)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}