#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    string s,ans="";
    in s;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)ans+=s[i];
    }
    cout<<ans<<endl;
}
