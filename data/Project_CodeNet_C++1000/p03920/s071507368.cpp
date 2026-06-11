#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N;
    cin>>N;
    vint ans;
    while(N){
        int n=1;
        while(n*(n+1)/2<N)n++;
        ans.pb(n);
        N-=n;
    }
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<endl;
    return 0;
}
