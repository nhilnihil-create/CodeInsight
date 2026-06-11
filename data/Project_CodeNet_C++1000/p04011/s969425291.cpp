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
    int a,b,c,d;
    scn(a);
    scn(b);
    scn(c);
    scn(d);

    int ans=0;

    if(a<=b)
    {
        cout<<a*c<<endl;
        return 0;
    }

    ans=ans+b*c;
    a=a-b;

    ans=ans+a*d;
    cout<<ans<<endl;
}

