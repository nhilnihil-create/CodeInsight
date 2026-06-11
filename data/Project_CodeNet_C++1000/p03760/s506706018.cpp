#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;

int main()
{
    string o;
    string e;
    in e>>o;
    rep(i,e.size())
    {
        cout<<e[i];
        if(i<o.size())cout<<o[i];
    }
}
