#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N;cin>>N;
    string s,t;cin>>s>>t;
    const ll MOD=1000000007;
    ll res=(s[0]==t[0]?3:6);
    s=s+'#';
    t=t+'#';
    REP(i,N-1){
        if(s[i+1]==s[i])continue;
        else{
			if(s[i]!=t[i] && s[i+1]==t[i+1])continue;
            else if(s[i]!=t[i] && s[i+1]!=t[i+1]){res*=3;res%=MOD;}
          else if(s[i]==t[i] && s[i+1]==t[i+1]){res*=2;res%=MOD;}
          else {res*=2;res%=MOD;}
        }
    }
    cout<<res<<endl;
    return 0;
}