#include <cstdio>
#include <utility>
#include <typeinfo>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
using namespace std;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;


int main()
{
    int h,w;
    cin >> h >> w;
    int a = -1;
    for(int i=0;i<900;i++)
    {
        a++;
        string s;
        cin >> s;
        if(s == "snuke")
        {
            break;
        }
    }

    char tate = 'A' + a%w;
    int yoko = a/w;

    cout << tate << yoko + 1 << endl;

   return 0 ;
}
