#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

vector <ll> enm_divisorsb(ll N){
    vector <ll> res;
    for (ll i=1; i*i<=N; i++){
        if(N%i==0) res.push_back(i);
        else continue;
    }
    return res;
    }
int main(){
    ll N; cin>>N;
    vector<ll> a=enm_divisorsb(N);
    ll sizea=a.size();
    ll count1=0;
    ll count2=0;
    ll notrest=a[sizea-1];
    while(notrest!=0){
        notrest/=10;
        count1++;
    }
    ll rest=N/a[sizea-1];
    while(rest!=0){
        rest/=10;
        count2++;
    }

    cout<<max(count1,count2)<<endl;




}