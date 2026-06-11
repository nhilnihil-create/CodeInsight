#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);

ll cnt[10005];
const int MAXN = 10005;
bool is[MAXN];
int prime[MAXN];
int Cnt = 0;
void getprime()
{
    memset(is, 1, sizeof(is));
    is[0] = is[1] = 0;
    for(int i = 2; i < MAXN; i++)
    {
        if(is[i])
        {
            prime[Cnt++] = i;
        }
        for(int j = 0; j < Cnt; j++)
        {
            if(i * prime[j] >= MAXN) break;
            is[i * prime[j]] = 0;
            if(i % prime[j]) break;
        }
    }
}
const int mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    getprime();
    /*for(int i = 0; i < 10; i++)
    {
        cout << prime[i] << endl;
    }*/
    for(int i = 2; i <= n; i++)
    {
        int num = i;
        int cur = 0;
        while(num > 1)
        {
            while(num % prime[cur] == 0)
            {
                cnt[prime[cur]]++;
                num /= prime[cur];
            }
            cur++;
        }
    }
    ll ans = 1;
    for(int i = 0; i < MAXN; i++)
    {
        if(cnt[i])
        {
            ans = ans * (cnt[i] + 1);
            ans %= mod;
        }
    }
    cout << ans << endl;
}