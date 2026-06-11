#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=998244353;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e9+7;
const long double PI=acos(-1);

int a[11];

bool ch(int n){
    bool ret=0;
    while(n){
        if(a[n%10])ret=1;
        n/=10;
    }
    return ret;
}

void solve(int T){
    int n,l;
    cin>>n>>l;
    for(int i=0;i<l;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    while(ch(n))n++;
    cout<<n<<"\n";
}
int main() {
    fastio

    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
	return 0;
}
