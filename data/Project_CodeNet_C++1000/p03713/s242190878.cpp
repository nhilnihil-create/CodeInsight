#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define pvec(v) rep(i,v.size()){cout << v[i] << " ";};cout<<endl;
#define pb push_back
#define pf push_front
#define mod 1e9+7
#define m_p make_pair
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
const double pi = acos(-1.0);
 
ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll h,w,ans=999999999,a,b,c;
    cin >> h >> w;
    if(h%3==0 || w%3==0) ans=0;
    else{
        if(w%3==1){
            a=(w/3)*h;
            b=(w/3)*h;
            c=((w+2)/3)*h;
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
        else if(w%3==2){
            a=(w/3)*h;
            b=((w+1)/3)*h;
            c=((w+1)/3)*h;
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
        if(h%3==1){
            a=(h/3)*w;
            b=(h/3)*w;
            c=((h+2)/3)*w;
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
        else if(h%3==2){
            a=(h/3)*w;
            b=((h+1)/3)*w;
            c=((h+1)/3)*w;
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
        for(ll i=1;i<w;i++){
            a=i*h;
            b=(w-i)*(h/2);
            c=(w-i)*((h+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
        for(ll i=1;i<h;i++){
            a=i*w;
            b=(h-i)*(w/2);
            c=(h-i)*((w+1)/2);
            ans=min(ans,max({a,b,c})-min({a,b,c}));
        }
    }
    cout << ans << endl;
    return 0;
}