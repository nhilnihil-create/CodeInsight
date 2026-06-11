#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

vint idx[222222];
string S;
int N;

int dp[222222];

signed main(){
    cin>>S;
    S="a"+S;
    N=S.size();

    rep(i,S.size())idx[S[i]-'a'].pb(i);

    for(int i=N-1;i>=0;i--){
        int mi=INT_MAX;
        rep(j,26){
            auto it=upper_bound(all(idx[j]),i);
            if(it==idx[j].end())mi=0;
            else chmin(mi,dp[*it]);
        }
        dp[i]=mi+1;
    }

    string ans;
    int las=0;

    int cnt=dp[0];
    rep(ei,cnt){
        int mi=INT_MAX,arcmi,arcidx;
        rep(i,26){
            auto it=upper_bound(all(idx[i]),las);
            int k;
            if(it==idx[i].end())k=N;
            else k=*it;
            if(mi>dp[k]){
                mi=dp[k];
                arcmi=i;
                arcidx=k;
            }
        }

        cout<<(char)(arcmi+'a');
        las=arcidx;
    }
cout<<endl;

    return 0;
}
