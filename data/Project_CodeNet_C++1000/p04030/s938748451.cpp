/*Always success does not build on success,success build on failure and hardwork*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define vec         vector<int>
#define map         map<int,int>
#define scn(t)      scanf("%d",&t);
#define lscn(t)      scanf("%lld",&t);
#define mod         1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define endl        "\n"
using namespace std;
const int N=2e5+5;

int main()
{
    string s;
    cin>>s;

    vec v;

    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]=='B')
        {
            if(v.size())
            v.pop_back();
            else
            continue;
        }
        else if(s[i]=='0')
        {
            v.pb(0);
        }
        else
        {
            v.pb(1);
        }
    }

    for(auto it: v)
    cout<<it;
}

