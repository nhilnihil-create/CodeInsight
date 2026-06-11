#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;

ll F(char c){
    if(c!='a')return 'z'-c+1;
    return 0;
}

int main(){
    string S;
    cin >> S;
    ll K;
    cin >> K;
    ll mark=0;
    while(K>0){
        if(F(S[mark])<=K){
            K-=F(S[mark]);
            S[mark]='a';
        }
        mark++;
        if(mark==S.size()){
            ll k=K;
            for(ll i=0;i<k;i++){
                if(S[mark-1]!='z')S[mark-1]++;
                else S[mark-1]='a';
                K--;
            ;}
        }
    }
    cout<<S<<endl;
    return 0;
}
