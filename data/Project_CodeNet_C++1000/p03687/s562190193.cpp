#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

bool OneCharStr(string S){
    char c=S.front();
    string _S(S.size(),c);
    if(S==_S) return true;
    else return false;
}

int main(){
    string S; cin>>S;

    int ans=INT_MAX;
    for(char c='a';c<='z';c++){
        int _ans=0;
        string _S=S;

        while(!OneCharStr(_S)){
            _ans++;
            rep(i,0,_S.size()){
                if(_S.at(i)==c && i!=0) _S.at(i-1)=c;
            }
            _S.erase(_S.size()-1);
        }

        ans=min(ans,_ans);
    }

    cout<<ans<<endl;
}