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

int gcd(int a,int b){
    int temp;
    while(b!=0){
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main(){
    int n,k; cin>>n>>k;
    vector<int> a(n,0);
    rep(i,n) cin>>a[i];
    sort(al(a));
    int GCD=a[0];
    rep(i,n-1) GCD=gcd(GCD,a[i+1]);
    if(k<=a.back() && k%GCD==0)
    cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}