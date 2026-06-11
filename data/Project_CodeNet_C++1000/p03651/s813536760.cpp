#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

long long gcd(long long m,long long n){
    if(n==0){
        return m;
    }
    return gcd(n,m%n);
}
 
long long lcm(long long a,long long b){
    long long g=gcd(a,b);
    return a/g*b;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(all(a));
    if(k>a[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    int g=0;
    rep(i,n) g=gcd(g,a[i]);
    rep(i,n){
        if(a[i]==k){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }

    if(k%g==0){
        cout<<"POSSIBLE"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}