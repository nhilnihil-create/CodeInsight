#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    int x,y,z;
    cin>>x>>y>>z;
    if (z-y<=0)
        cout<<"delicious\n";
    else if (z-y<=x)
        cout<<"safe\n";
    else
        cout<<"dangerous\n";
    return 0;
}
