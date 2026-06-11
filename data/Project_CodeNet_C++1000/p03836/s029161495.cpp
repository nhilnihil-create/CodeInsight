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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int x = tx - sx;
    int y = ty - sy;
    for(int i = 0; i < y; i++)
    {
        cout << 'U';
    }
    for(int i = 0; i < x; i++)
    {
        cout << 'R';
    }
    for(int i = 0; i < y; i++)
    {
        cout << 'D';
    }
    for(int i = 0; i <= x; i++)
    {
        cout << 'L';
    }
    for(int i = 0; i <= y; i++)
    {
        cout << 'U';
    }
    for(int i = 0; i <= x; i++)
    {
        cout << 'R';
    }
    cout << "DR";
    for(int i = 0; i <= y; i++)
    {
        cout << 'D';
    }
    for(int i = 0; i <= x; i++)
    {
        cout << 'L';
    }
    cout << 'U';
    cout << endl;
    //cout << "UURRURRDDDLLDLLULUUURRURRDDDLLDL" << endl;
    return 0;
}