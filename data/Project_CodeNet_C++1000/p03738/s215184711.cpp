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
int c,d;

if (a.size()>b.size())
{
    cout<<"GREATER"<<endl;
}
else if (a.size()<b.size())
{
    cout<<"LESS"<<endl;
}
else {
if (a>b)
{
    cout<<"GREATER"<<endl;
}
else if (a<b)
{
    cout<<"LESS"<<endl;
}

else cout<<"EQUAL"<<endl;
}



    return 0;
}