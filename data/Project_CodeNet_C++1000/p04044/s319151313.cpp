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
const int N=1e5+5;
bool comp(string a,string b)
{
    string ab=a+b;
    string ba=b+a;

    if(ab<ba)
    return 1;
    else
    return 0;
}
int main()
{
      int n;
      scn(n);

      int l;
      scn(l);
      vector<string> s;

      rep(i,0,n)
      {
          string a;
          cin>>a;
          s.pb(a);
      }

      sort(s.begin(),s.end(),comp);

      for(auto it: s)
      cout<<it;
}

