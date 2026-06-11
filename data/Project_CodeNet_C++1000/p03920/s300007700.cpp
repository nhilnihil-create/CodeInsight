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
    ll n ;
    cin >> n;
    int m = 0;
    if(n==1){cout<<1<<endl;return 0;}
    int sum = 0;
    for(int i=0; i<n ;i++)
    {
        if(sum + i + 1 > n )
        {
            m = i;
            break;
        }
        else
        {
            sum += i + 1;
        }
    }

    for(int i = 0; i < m;i++)
    {
        if(i < m - (n - sum))
        {
            cout << i+1 << endl;
        }
        else
        {
            cout << i+2 << endl;
        }
    }

   return 0 ;
}
