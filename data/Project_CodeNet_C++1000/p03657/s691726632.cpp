#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int N=1e2+9;
int main()
{
    FASTINOUT;
    int x,y;
    cin>>x>>y;
    if (x%3==0||y%3==0||(x+y)%3==0)
    cout<<"Possible\n";
    else
    cout<<"Impossible\n";
    return 0;
}
