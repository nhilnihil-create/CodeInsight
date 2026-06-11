#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

#define user spaesk
#define lli long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<lli> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

lli f[N];

void solve()
{

    lli n, L;
    cin>>n >> L;
    lli a[n];
    lli idx = -1;
    for(int i = 0; i < n; i ++) {
        cin>>a[i];
        if(a[i] >= L) {
            idx = i;
        }
    }

    if(idx != -1 ) {
        cout<<"Possible\n";
        for(int i = 1; i <= idx; i ++) {
            cout<<i<<'\n';
        }
        for(int i = n - 1; i >= idx + 1; i --) {
            cout<<i<<'\n';
        }
        return ;
    }

    for(int i = 1; i < n; i ++) {
        if(a[i] + a[i - 1] >= L) {
            cout<<"Possible\n";
            for(int j = 1; j <= i - 1; j ++) {
                cout<<j<<'\n';
            }
            for(int j = n - 1; j >= i; j --) {
                cout<<j<<'\n';
            }
            return ;
        }
    }

    cout<<"Impossible";

    cout<<"\n";
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
