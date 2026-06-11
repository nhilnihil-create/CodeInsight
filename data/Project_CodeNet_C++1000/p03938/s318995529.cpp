#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    ll a[n],b[n];
    for(int i=0;i<n;i++){
        a[i]=n*i+1;
    }
    for(int i=0;i<n;i++){
        b[n-i-1]=n*i+1;
    }
    for(int i=0;i<n;i++){
        a[p[i]]+=i;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout << endl;

    return 0;
}