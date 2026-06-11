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
    ll x;
    cin >> x;
    ll shou = x/11;
    if(x%11==0)
    {
        cout << shou*2 << endl;
    }else
    {
        if(x%11>6)
        {
            cout << (shou+1)*2<< endl;
        }else
        {
            cout << 2*shou+1 << endl;
        }
        
    }
    

}