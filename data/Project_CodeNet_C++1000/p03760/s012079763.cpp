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
    string s,s1;
    cin>>s>>s1;
    for(i=0;i<s1.size();i++)
        cout<<s[i]<<s1[i];
    if(s.size()!=s1.size())
        cout<<s[s.size()-1];

    return 0;
}
