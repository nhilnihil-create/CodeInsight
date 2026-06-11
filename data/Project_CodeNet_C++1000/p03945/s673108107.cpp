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
    string op;
    cin >> op;
    string n;
    for(int i = 0; i < op.size(); i++)
    {
        if(i == 0)
        {
            n += op[i];
        }
        else
        {
            if(op[i] != n[n.size() - 1])
            {
                n += op[i];
            }
        }
        
    }
    cout << n.size() - 1 << endl;
}