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
    ll a[n],d[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            d[i-1]=a[i]-a[i-1];
        }
        sum+=a[i];
    }
    d[n-1]=a[0]-a[n-1];
    ll k=sum/(n*(n+1)/2);
    if(sum==k*(n*(n+1)/2)){
        for(int i=0;i<n;i++){
            if(d[i]<=k&&(d[i]-k)%n==0){
                continue;
            }
            else{
                cout << "NO"<<endl;
                return 0;
            }
        }
        cout << "YES"<<endl;
    }
    else{
        cout <<  "NO"<<endl;
    }
    return 0;
}
