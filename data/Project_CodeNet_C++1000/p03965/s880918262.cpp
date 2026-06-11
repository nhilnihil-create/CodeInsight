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
    int g = 0, p = 0, ans = 0;
    for(int i = 0; i < op.size(); i++)
    {
        if(g <= p)
        {
            g++;
            if(op[i] == 'g')
            {
                ;
            }
            else
            {
                ans--;
            }
            
        }
        else
        {
            if(op[i] == 'g')
            {
                p++;
                ans++;
            }
            if(op[i] == 'p')
            {
                p++;
            }
        }
        
    }
    cout << ans << endl;
    
}