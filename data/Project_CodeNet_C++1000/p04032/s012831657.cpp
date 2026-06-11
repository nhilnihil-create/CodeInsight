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
 
    int l=s.length();
 
    for(int i=0;i<l-1;i++)
    {
        if(s[i]==s[i+1])
        {
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
    }
 
    for(int i=0;i<l-2;i++)
    {
        if(s[i]==s[i+2])
        {
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }
    }
 
    cout<<-1<<" "<<-1<<endl;
}