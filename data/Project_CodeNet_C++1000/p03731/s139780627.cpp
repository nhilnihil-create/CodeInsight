#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten53 300005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;

ll num[ten52];

int main(void)
{
    ll m,n,i,j,k=1,d,sum=0;
    string s;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>num[i];
    for(i=0;i<n-1;i++)
    {
        if(num[i]+m<=num[i+1])
            sum+=m;
        else
            sum+=(num[i+1]-num[i]);
    }
    sum+=m;
    cout<<sum;
    return 0;
}
