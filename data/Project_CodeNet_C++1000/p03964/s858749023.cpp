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

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll t, a;
    for(int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        if(!i)
        {
            t = l;
            a = r;
        }
        else
        {
            if(t > l && a <= r)
            {
                ll time = t / l;
                if(t % l) time++;
                t = l * time;
                a = r * time;
            }
            else if(t <= l && a > r)
            {
                ll time = (a / r);
                if(a % r) time++;
                t = l * time;
                a = r * time;
            }
            else if(t > l && a > r)
            {
                ll time = t / l;
                if(t % l) time++;
                ll tmp = a / r;
                if(a% r) tmp++;
                time = max(time, tmp);
                t = l * time;
                a = r * time;
            }
            else if(t <= l && a <= r)
            {
                t = l;
                a = r;
            }
        }
        //cout << t << ' ' << a << endl;
    }
    cout << t + a << endl;
}