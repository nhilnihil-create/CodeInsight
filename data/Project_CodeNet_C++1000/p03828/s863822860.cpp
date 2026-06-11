#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;


int main()
{
    int n;
    cin >> n;
    vector<ll> sosu(n+1);
    rep(i,n+1)sosu[i] = (ll)0;
    int temp_n;
    for(int nn = 2; nn<= n; nn++)
    {
        int temp_n = nn;
        for (int num = 2; num * num <= temp_n; num++)
        {
            while (temp_n % num == 0)
            {
                sosu[num]++;
                temp_n /= num;
            }
        }
        sosu[temp_n]++;
    }
    
    
    ll ans = 1;
    for (int i = 2; i <=n; i++)
    {
        if(sosu[i]!=0)
        {
            ll temp = sosu[i] + 1;
            ans *= temp;
            ans %= MOD;
        }
    }
    cout << ans << endl;


    

    
    

}