#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    sort(all(t));
    ll bus=0,i=0,j=0;
    while(j<n){
        ll limit=t[i]+k,passenger=0;
        for(j=i;j<n;j++){
            if(t[j]>limit||passenger==c){
                i=j;
                break;
            }
            passenger++;
        }
        bus++;
    }
    cout<<bus;
}