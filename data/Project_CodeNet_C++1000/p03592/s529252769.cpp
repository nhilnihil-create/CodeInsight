#include <iostream>    // cin, cout
#include <string>    // string, stoi, to_string
#include <algorithm>    // sort, lower_bound, heap, min, next_permutation 
#include <functional>    // greater, less
#include <vector>    // vector
#include <stack>    // stack
#include <queue>    // queue
#include <list>    // list
#include <map>    // map
#include <set>    // set
#include <tuple>    // tuple
#include <bitset>    // bitset
#include <cstdio>  // fopen, printf, scanf, puts
#include <cmath>    // sin, exp, log, pow, sqrt
#include <iomanip>    // setfill, setbase

using namespace std;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30));
const long long linf = (1LL<<60);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    bool ok = false;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            int tmp;
            tmp = i*m + j*n - 2*i*j;
            if(tmp == k)
            {
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
