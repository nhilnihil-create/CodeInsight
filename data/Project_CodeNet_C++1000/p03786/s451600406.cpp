#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const static ll MOD = (1e+9)+7;

int main(){
    ll N;cin>>N;
    vector<ll> A(N);rep(i,N)cin>>A[i];
    sort(A.begin(),A.end(),greater<ll>());
    ll ans = 0, sum = 0;
    rep(i,N)sum+=A[i];
    rep(i,N){
        sum -= A[i];
        ans++;
        if(sum*2 < A[i])break;
    }
    cout<<ans<<endl;
    return 0;
}