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
const int MAXN = 1e5+5;
int a[MAXN];
int MIN[MAXN];
int MAX[MAXN];
int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(!i)
        {
            MIN[i] = a[i];
        }
        else
        {
            MIN[i] = min(MIN[i - 1], a[i]);
        }
        
    }
    for(int i = n -1 ;i  >= 0; i--)
    {
        if(i == n-1)
        {
            MAX[i] = a[i];
        }
        else
        {
            MAX[i] = max(MAX[i + 1], a[i]);
        }
        
    }
    int dis = -1;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        dis = max(dis, MAX[i] - MIN[i]);
    }
    //dbg(dis);
    int maxx = -1, minn = -1;
    for(int i = 0; i < n; i++)
    {
        if(MAX[i] - MIN[i] == dis && maxx != MAX[i] && minn != MIN[i])
        {
            maxx = MAX[i];
            minn = MIN[i];
            ans++;
        }
    }
    cout << ans << endl;
}