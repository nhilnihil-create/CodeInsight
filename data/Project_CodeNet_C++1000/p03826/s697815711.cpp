#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e6+6;
const int mod = 1e9+7;
const int inf = 1e8;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a*b,c*d)<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
