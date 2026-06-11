#include<iostream>
#include<string>
#include<algorithm>
#include <sstream>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include <vector>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;
    ll sumx=0,sumy=0;
    int ln;
    ll num;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        sumx+=num*(i-1)-num*(n-i);
        sumx=sumx%mod;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>num;
        sumy+=num*(i-1)-num*(m-i);
        sumy=sumy%mod;
    }
    cout<<sumx*sumy%mod<<endl;
    return 0;
}
