#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    int x,y;
    cin>>x>>y;
    if (x<y&&x!=1)
        cout<<"Bob\n";
    else if (x>y&&y!=1)
        cout<<"Alice\n";
    else if (x==y)
        cout<<"Draw\n";
    else if (x==1)
        cout<<"Alice\n";
    else
        cout<<"Bob\n";
    return 0;
}
