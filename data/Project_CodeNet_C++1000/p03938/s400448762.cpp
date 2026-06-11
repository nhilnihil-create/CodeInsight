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
    vector<int> p(n,0),a(n,0),b(n,0);
    rep(i,n){
        cin>>p[i]; p[i]--;
    }
    rep(i,n) a[i]=i*20000+1;
    for(int i=n-1;i>=0;i--) b[i]=(n-i)*20000+a.back();
    rep(i,n) b[p[i]]+=i;
    rep(i,n){
        cout<<a[i];
        if(i<n-1) cout<<" ";
    }
    cout<<endl;
    rep(i,n){
        cout<<b[i];
        if(i<n-1) cout<<" ";
    }
    cout<<endl;
}
