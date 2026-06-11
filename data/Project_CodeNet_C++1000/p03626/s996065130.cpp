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
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    string s1,s2;cin >> s1 >> s2;
    string domino[] = {s1,s2};
    ll ans = 1;
    int index = 0;
    char state;
    while(index <n)
    {
        if(index==0)
        {
            if(domino[0][index]==domino[1][index])
            {
                ans *= 3;
                index++;
                state = 'x';
                continue;
            }else
            {
                ans *= 6;
                index += 2;
                state = 'y';
                continue;
            }
        }
        if (state == 'x')
        {
            if (domino[0][index] == domino[1][index])
            {
                ans *= 2;
                ans %= MOD;
                index++;
                state = 'x';
                continue;
            }
            else
            {
                ans *= 2;
                ans %= MOD;
                index += 2;
                state = 'y';
                continue;
            }
        }
        else
        {
            if (domino[0][index] == domino[1][index])
            {
                ans *= 1;
                ans %= MOD;
                index++;
                state = 'x';
                continue;
            }
            else
            {
                ans *= 3;
                ans %= MOD;
                index += 2;
                state = 'y';
                continue;
            }
        }
    }
    cout << ans << endl;
    
}