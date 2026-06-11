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
const int MAXN = 1e5 + 5;
ll num[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i <n ; i++)
    {
        cin >> num[i];
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++)
    {
        if((num[i + 1] - num[i]) * a > b)
        {
            ans += b;
        }
        else
        {
            ans += (num[i + 1] - num[i]) * a;
        }
        
    }
    cout << ans << endl;

}