#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    string Sc;
    cin>>Sc;
    int ans=INF;
  	string S;
    for(int i=0;i<26;i++){
        S=Sc;
      	int count=0;
        char d='a'+i;
        bool ok=true;
        REP(i,S.size()-1){
            if(S[i]!=S[i+1])ok=false;
        }
      	if(ok)ans=0;
        while(!ok){
            bool che=false;
            REP(i,S.size()-1){
                if(S[i]==d||S[i+1]==d){
                    S[i]=d;
                    che=true;
                }
            }
            if(!che){
                break;
            }
            count++;
            S=S.substr(0,S.size()-1);
            ok=true;
            REP(i,S.size()-1){
            if(S[i]!=S[i+1])ok=false;
            }
        }
        if(count!=0)ans=min(count,ans);    
    }
  	cout<<ans<<endl;
}