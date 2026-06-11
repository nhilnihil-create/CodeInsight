#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(){
    int n,k; cin>>n>>k;
    vector<int> a(n),sum1(n+1,0),sum2(n+1,0);
    int Sum1=0,Sum2=0;
    rep(i,n){
        cin>>a.at(i);
        Sum1+=a.at(i);
        if(a.at(i)>0)Sum2+=a.at(i);
        sum1.at(i+1)=Sum1;
        sum2.at(i+1)=Sum2;
    }
    int ans=-INF;
    for(int i=0; i+k<=n; i++){
        chmax(ans, max<int>(0,sum1.at(i+k)-sum1.at(i))+sum2.back()-sum2.at(i+k)+sum2.at(i));
    }
    cout<<ans<<endl;
}