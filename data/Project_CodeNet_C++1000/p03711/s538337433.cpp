#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VS = vector<string>;
using graph = vector<vector<int>>;
int main()
{
VI che={1,3,1,2,1,2,1,1,2,1,2,1};
int a,b;
cin>>a>>b;
if (che.at(a-1)==che.at(b-1))
{
    cout<<"Yes"<<endl;  
}
else
{
    cout<<"No"<<endl;
}

    return 0;
}