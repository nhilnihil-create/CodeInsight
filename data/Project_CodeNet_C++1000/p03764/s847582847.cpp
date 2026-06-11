#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define taskname "A"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int n , m , a , b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP" , "r"))
        freopen(taskname".INP","r",stdin),
        freopen(taskname".OUT","w",stdout);
    cin >> n >> m;
    ll res = 0 , res1 = 0 , sum = 0 , sum1 = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a;
        res += (ll)a * (i - 1) - sum;
        sum += a;
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> b;
        res1 += (ll)b * (i - 1) - sum1;
        sum1 += b;
    }
    cout << (res % mod) * (res1 % mod) % mod;
}
