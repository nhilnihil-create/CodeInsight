#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    string S;
    ll K;
    cin>>S>>K;
    for(ll i=0;i<S.size();i++){
        int cnt=(26-S[i]+'a')%26;
        if(K>=cnt){
            S[i]='a';
            K-=cnt;
        }
    }
    K%=26;
    if(K>0){
        int cnt=S[S.size()-1]-'a';
        S[S.size()-1]='a'+(cnt+K)%26;
    }
    cout<<S<<endl;
}