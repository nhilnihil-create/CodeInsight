#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    cin>>k;
    if(k==0){
        cout << 2<<endl<<0<<" "<<0<<endl;
        return 0;
    }
    ll m=(k-1)/50;
    ll a[50];
    a[0]=50+m;
    k%=50;
    if(k==0)k=50;
    for(ll i=1;i<50;i++){
        if(i<k){
            a[i]=a[0]-i;
        }else{
            a[i]=a[0]-i-1;
        }
    }
    cout << 50<<endl;
    for(int i=0;i<50;i++)cout << a[i]<<" ";
    cout << endl;
    return 0;
}
