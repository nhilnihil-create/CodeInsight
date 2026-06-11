#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e3+6;
const int mod = 1e9+7;
const ll inf = 1e18;
int a[N];
void solve(){
    string s;
    cin>>s;
    for(auto x:s){
        if(x==',')cout<<" ";
        else cout<<x;
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
