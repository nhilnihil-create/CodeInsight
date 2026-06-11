#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES
 
long long binpow(long long a,long long b)
{
    if (b == 1) return a;
    long long res = binpow(a, b/2)%MOD;
    if (b % 2) return (res*((res*a)%MOD))%MOD;
    else return (res * res)%MOD;
}

long long int fact(long long int a)
{
    if(a==0||a==1)
        return 1;
    long long int ans = 1;
    for(int i=a;i>=1;i--)
        ans = (ans * i)% MOD;
    return ans;
}

long long int ivmod(long long int a)
{
    return binpow(a,MOD-2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    int a[n+4];
    stack<int> s;
    long long int ans =1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
        if (x<=2*i) 
        {
            s.pop();
            ans=ans*(i + 1)%MOD;
            n--;
            i--;
        }
    }
    ans = ans*fact(s.size())%MOD;
    cout<<ans<<endl;
    return 0;
}