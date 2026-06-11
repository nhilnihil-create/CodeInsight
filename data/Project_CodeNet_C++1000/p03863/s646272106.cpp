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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string op;
    cin >> op;
    int n = op.size();
    int ans = 0;
    if(op[0] == op[n - 1])
    {
        ans = n - 3;
    }
    else
    {
        ans = n - 2;
    }
    
    if(ans % 2)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
    
}