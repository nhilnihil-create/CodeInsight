#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

//解説
int main(void){
    int n;
    cin>>n;
    long long takahashi=1,aoki=1;
    rep(i,n){
        long long t,a;
        cin>>t>>a;
        long long nt=(takahashi+t-1)/t;
        long long na=(aoki+a-1)/a;
        long long n=max(nt,na);
        takahashi=n*t;
        aoki=n*a;
        //cout<<takahashi<<" "<<aoki<<endl;
    }
    cout<<takahashi+aoki<<endl;
    return 0;
}
