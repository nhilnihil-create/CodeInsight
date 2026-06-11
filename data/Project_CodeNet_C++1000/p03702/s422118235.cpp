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
    ll n,a,b;
    cin>>n>>a>>b;
    ll h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    } 
    ll mi=0,ma=10000000000,mid=(mi+ma)/2;
    bool maki;
    ll num;
    while(mi!=mid){
        maki=false;
        num=0;
        for(int i=0;i<n;i++){
            num+=(max(0LL,h[i]-mid*b+a-b-1))/(a-b);
        }
        if(num<=mid)maki=true;
        if(maki){
            ma=mid;
        }else{
            mi=mid;
        }
        mid=(ma+mi)/2;
    }
    cout << ma<<endl;
    return 0;
}
