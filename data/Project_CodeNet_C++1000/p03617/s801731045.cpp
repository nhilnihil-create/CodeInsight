#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
typedef pair<ll, ll> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    // ll q,h,s,d;cin >> q >> h >> s >> d;
    vector<ll> b(4);
    priority_queue<P, vector<P>, greater<P>> pq;
    ll num = 8;
    rep(i,4)
    {
        ll temp;cin >> temp;
        b[i] = temp;
        pq.push(P(num*temp,(ll)i));
        num/=2;
    }
    ll n;cin >> n;
    n = 4*n;
    ll sum = 0;
    while(true)
    {
        ll index = pq.top().second;
        pq.pop();
        //cout << index << endl;
        ll div = 1;
        for (ll i = 0; i < index; i++)
        {
            div *= 2;
        }
        
        ll kosu = n/div;
        n %=div;
        //cout << n << endl;
        sum += b[index]*kosu;
        if(n==0)
        {
            break;
        }
    }
    cout << sum << endl;
}