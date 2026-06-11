#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrepa(i,a,n) for(int i=(n)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main(){
   
    ll n,x;
    cin >> n >> x;
    ll ans=n;

    ll a=n-x,b=x;
    if(a<b)swap(a,b);

    ll tmp;
    while(a%b != 0){
        tmp = a/b;
        ans += 2*b*tmp;
        a -= b*tmp;
        swap(a,b);
    }
    ans += b*((a/b)*2-1);

    cout << ans << endl;
    
    return 0;
}