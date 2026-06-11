#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VB = vector<bool>;
using VS = vector<string>;
using graph = vector<vector<int>>;

int main()
{
string a,b;
cin>>a>>b;
int num=a.length(),aaaa=b.length();
num=num+aaaa;
int x=0,y=0;
for (int i = 1; i <= num; i++)
{
    if (i%2==1)
    {
        cout<<a.at(x);
        x++;
    }
    else
    {
        cout<<b.at(y);
        y++;
    }
    
}
cout<<endl;
    return 0;
}