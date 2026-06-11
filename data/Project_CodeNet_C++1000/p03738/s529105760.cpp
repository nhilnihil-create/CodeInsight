#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define ull unsigned long long
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;
const int MOD=1e9+7;

int main()
{
    string a,b;
    cin>>a>>b;
    if(a.length() < b.length())
    {
        cout<<"LESS"<<endl;
        return 0;
    }
    if(a.length() > b.length())
    {
        cout<<"GREATER"<<endl;
        return 0;
    }

    rep(i,a.size())
    {
        if(a[i]-'0' < b[i]-'0')
        {
            cout<<"LESS"<<endl;
            return 0;
        }
        if(a[i]-'0' > b[i]-'0')
        {
            cout<<"GREATER"<<endl;;
            return 0;
        }
    }
    cout<<"EQUAL"<<endl;;
}
