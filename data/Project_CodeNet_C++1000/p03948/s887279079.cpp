#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define P pair<int,int>
#define PP pair<P,int>
#define fi first
#define se second
#define INF 1e9
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()
int main(){
    int n,m;
    cin>>n>>m;
    vi vec(n);
    REP(i,n)cin>>vec[i];
    vi ma(n);
    ma[n-1]=vec[n-1];
    REPR(i,n-2){
        ma[i]=max(ma[i+1],vec[i]);
    }
    vi di(n);
    int k=0;
    REP(i,n){
        di[i]=ma[i]-vec[i];
        k=max(k,di[i]);
    }
    int ans=0;
    REP(i,n){
        if(di[i]==k){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}