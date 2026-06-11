#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;

    if(a>b){
        cout<<0<<endl;
        return 0;
    }

    if(n==1 && a!=b){
        cout<<0<<endl;
        return 0;
    }

    ll mi=a*(n-1)+b;
    ll ma=a+b*(n-1);
    cout<<ma-mi+1<<endl;
}