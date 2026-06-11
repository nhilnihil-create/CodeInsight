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
int a,b,c;
bool j=false;
cin>>a>>b>>c;
for (int  i = 1; i <= b; i++)
{
    if ((a*i)%b==c)
    {
j=true;
    }
    
}
if (j==1)
{
    cout<<"YES"<<endl;
}
else
{
    cout<<"NO"<<endl;
}

    return 0;
}