#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    string A;cin>>A;
    ll N=A.size();
    ll ans=N*(N-1)/2+1;
    ll i=0,j=0;
    map<char,ll> mp;
    // while(i<N){
    //     while(j<N && A[j]==A[i]){
    //         ++j;
    //     }
    //     ll n=j-i;
    //     if(i>0&&j<N-1&&A[i-1]==A[j+1]){
    //         ans -= n;
    //     }
    //     i=j;
    // }
    REP(i,N) mp[A[i]]++;
    for(auto e:mp){
        ans-=e.second*(e.second-1)/2;
    }
    cout<<ans<<endl;
}
