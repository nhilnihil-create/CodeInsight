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
#define INF (1ll<<60)
signed main(){
    int A,B,C,D,E,F,G; cin>>A>>B>>C>>D>>E>>F>>G;
    int sum=min({A,D,E});
    int ans=sum*3;
    ans+=(A-sum)/2*2;
    ans+=(D-sum)/2*2;
    ans+=(E-sum)/2*2;
    ans+=B;
    int sum2=(A-sum)%2+(D-sum)%2+(E-sum)%2;
    if(sum2==2&&sum>=1) ans++;
    cout<<ans<<endl;
}