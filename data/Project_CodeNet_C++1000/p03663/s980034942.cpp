#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<62)-1
#define MAX 1000000000
bool f(int X){
    printf("? %lld\n",X*10);
    char S; cin>>S;
    return S=='Y';
}
void solve(){
    int ans=10;
    while(1){
        printf("? %lld\n",ans-1);
        char S; cin>>S;
        if(S=='Y'){
            printf("! %lld\n",ans/10);
            return;
        }
        ans*=10;
    }
}
signed main(){
    int memo=10;
    while(1){
        printf("? %lld\n",memo);
        string S; cin>>S;
        if(S=="N") break;
        memo*=10;
        if(memo>=1e11){
            solve();
            return 0;
        }
    }
    int left=memo/10,right=memo-1;
    while(left+1<right){
        int mid=(left+right)/2;
        if(f(mid)) right=mid;
        else left=mid;
    }
    int ans=right;
    if(f(left)) ans=left;
    printf("! %lld\n",ans);
}
