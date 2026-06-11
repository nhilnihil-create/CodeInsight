#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;

void dfs(string s,int n){
    if(n==0){
        cout<<s<<endl;
    }else{
        char k[3]={'a','b','c'};
        rep(i,3)dfs(s+k[i],n-1);
    }
}

int main(void){
    string s;
    string t;
    int q;
    int a[110000];
    int b[110000];
    int c[110000];
    int d[110000];
    int ss[110000];
    int tt[110000];
    cin>>s>>t;
    cin>>q;
    rep(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];    
    
    rep(i,s.size()){
        if(s[i]=='A'){
            ss[i+1]+=ss[i]+1;
        }else{
            ss[i+1]+=ss[i]+2;
        }
    }
    rep(i,t.size()){
        if(t[i]=='A'){
            tt[i+1]+=tt[i]+1;
        }else{
            tt[i+1]+=tt[i]+2;
        }
    }
    
    rep(i,q){
        int m=ss[b[i]]-ss[a[i]-1]-tt[d[i]]+tt[c[i]-1];
        //cout<<ss[b[i]]<<ss[a[i]-1]<<'|'<<tt[d[i]]<<tt[c[i]-1];
        if(m%3==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    

}

