#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,p;
    cin>>n>>p;
    int m=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a%2==1) m++;
    }

    if(m==0) cout<<(p==0 ? (1LL<<n) : 0)<<endl;
    else cout<<(1LL<<(n-1))<<endl;
}