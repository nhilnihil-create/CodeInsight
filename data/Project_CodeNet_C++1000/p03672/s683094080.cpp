#include <bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define MOD 1000000007
#define int long long
using namespace std;
#define s second
#define f first

bool isEven(string &s, int n)
{
    if(n&1) return false;
    for(int i=0;i<n/2;i++)
    {
        if( s[i]!=s[n/2+i] )
            return false;
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length()-1;
    while( !isEven(s,n) )
        n--;
    cout << n;
}