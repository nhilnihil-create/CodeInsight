//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    rep(i,(n+1)/2){
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        cout<<a[n-1-2*i]<<" ";
    }
    rep(i,n/2){
        if(n%2) cout<<a[1+2*i];
        else cout<<a[2*i];
        if(i!=n/2-1) cout<<" ";
        else cout<<endl;
    }
}