#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <stack>
#define INT long long
#define MOD 1000000007
#define oo 987654321
#define OO 999999987654321ll
using namespace std;

INT n, ans = 1, k;
stack<INT> s;

int main()
{
    cin>>n;
    for(int i = 1 ; i <= n ; i++ )
    {
        int t;
        cin>>t;
        s.push(t);
        k = s.size();
        if( t < 2*k-1 ) s.pop();
        ans *= k;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}
