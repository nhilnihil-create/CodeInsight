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
const int MAXN = 1e5+5;
ll a[MAXN];
int main()
{
    //FIN;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n ,x ;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++)
    {
        int tmp  = a[i] + a[i-1] - x;
        if(tmp > 0)
        {
            if(tmp > a[i])
            {
                a[i] = 0;
                ans += tmp;
            }
            else
            {
                a[i] -= tmp;
                ans += tmp;
            }
        }

    }
    
    cout << ans << endl;
}