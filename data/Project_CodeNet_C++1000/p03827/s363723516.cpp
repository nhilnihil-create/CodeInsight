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


int main(void)
{
    ll m,n,i,j,k=0,d,sum=0;
    string s;
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(s[i]=='I')
            k++;
        else
            k--;
        sum=max(k,sum);
    }
    cout<<sum;
    return 0;
}
