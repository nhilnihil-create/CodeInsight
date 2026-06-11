#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod = (ll)10e9+7;
const int INF = 0x3f3f3f3f;

int a[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int n = str.length();
    if(n&1)
    {
        if(str[0]==str[n-1])
        {
            cout << "Second";
        }
        else cout << "First";
        return 0;
    }
    else
    {
        if(str[0]==str[n-1])
        {
            cout << "First";
        }
        else cout << "Second";
        return 0;
    }
}

//TODO: 48
