#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<ll>>;
#define MAX 1000000007
using ull=unsigned long long;

ull gcd(ull a,ull b)
{
    if(a%b==0){
        return b;
    }else{
        return (gcd(b,a%b));
    }
}

ull lcm(ull a,ull b)
{
    ull num=a/gcd(a,b);
    num*=b;
    return num;
}
int main()
{
    int n;
    cin >> n;
    vector<ull> t(n);
    rep(i,n)cin >> t[i];
    ull ans=1;
    rep(i,n){
        ans=lcm(ans,t[i]);
    }
    cout << ans << endl;
}