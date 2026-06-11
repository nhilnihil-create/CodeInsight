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
int a,b,c;
cin>>a>>b>>c;
if (a<=c&&b>=c)
{
    cout<<"Yes"<<endl;

}
else cout<<"No"<<endl;
    return 0;
}