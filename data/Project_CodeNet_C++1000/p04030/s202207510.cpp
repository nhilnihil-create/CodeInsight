#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
string s;
cin>> s;

stack<char> c;
for(char k : s)
{
    if(k=='B'&&!c.empty())
        c.pop();
    else if(k!='B')
        c.push(k);
}
string ans ="";

while(!c.empty())
{
    ans+=c.top();
    c.pop();
}
reverse(ans.begin(),ans.end());
cout<<ans<<endl;
 return 0;
}
