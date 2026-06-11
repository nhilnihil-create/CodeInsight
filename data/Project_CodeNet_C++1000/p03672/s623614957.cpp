#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll f()
{
ll l=s.size();

if(l&1)return 0;
l>>=1;
for(int i=0;i<l;i++)if(s[i]!=s[l+i])return 0;
return 1;

}
int main()
{
   
    cin>>s;
    while(!s.empty())
    {s.pop_back();
    if(f()){cout<<s.size()<<endl;return 0;}
    
    }
}