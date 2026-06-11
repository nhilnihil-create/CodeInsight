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
const int mod = 1e9 + 7;
int cnt[100005];
ll poww(ll a, ll b)
{
    ll ans = 1, base = a;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return ans % mod;
}
int main()
{
    //FIN;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int ans = -1;
    if(n % 2)
    {
        if(cnt[0] != 1)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            for(int i = 1; i < n; i++)
            {
                if(i % 2 && cnt[i])
                {
                   cout << 0 << endl;
            return 0;
                }
                if(i % 2 == 0 && cnt[i] != 2)
                {
                    cout << 0 << endl;
            return 0;
                }
            }
        }
        
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 && cnt[i] != 2)
            {
               cout << 0 << endl;
            return 0;
            }
            if(i % 2 == 0 && cnt[i])
            {
               cout << 0 << endl;
            return 0;
            }
        }
    }
    
    ans = poww(2, n / 2);
        cout << ans << endl;
    return 0;
    
    
}