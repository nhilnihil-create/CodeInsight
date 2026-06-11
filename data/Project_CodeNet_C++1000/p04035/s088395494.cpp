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
    ll n,x;
    cin>>n>>x;
    ll a[n];
    int num=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]>=x)num=i;
    }
    if(!num){
        cout << "Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    for(int i=1;i<num;i++){
        cout << i<<endl;
    }
    for(int i=n-1;i>num;i--){
        cout << i<<endl;
    }

    cout << num<<endl;
    return 0;
}
