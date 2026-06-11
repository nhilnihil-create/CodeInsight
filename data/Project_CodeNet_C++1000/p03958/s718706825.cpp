#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<" ";

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int k,t;
    cin>>k>>t;
    int a[t];
    int ma=0;
    for(int i=0;i<t;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    int maki=k-ma;
    if(ma+1<=maki){
        cout << 0<<endl;
    }else{
        ma-=maki;
        cout << ma-1<<endl;
    }
    return 0;
}
