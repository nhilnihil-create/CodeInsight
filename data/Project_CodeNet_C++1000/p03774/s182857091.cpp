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

ll num[55][2],point[55][2];

int main(void)
{
    ll m,n,i,j,k=1,d,sum=0;
    string s;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>k>>d;
        num[i][0]=k;
        num[i][1]=d;
    }
    for(i=0;i<m;i++)
    {
        cin>>k>>d;
        point[i][0]=k;
        point[i][1]=d;
    }
    for(i=0;i<n;i++)
    {
        sum=d=k=0;
        for(j=0;j<m;j++)
        {
            k=abs(num[i][0]-point[j][0])+abs(num[i][1]-point[j][1]);
            if(!sum)
                sum=k;
            else if(k<sum)
            {
                d=j;
                if(!k) break;
                sum=k;
            }
        }
        cout<<d+1<<endl;
    }
    return 0;
}
