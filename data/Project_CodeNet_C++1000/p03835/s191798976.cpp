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
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;


//stack<char> stk;
//set<ll> sll;
//set<pair<ll,ll>> spll;
//map<string,ll> mp;
//map<pair<ll,ll>,ll>::iterator iter;
//map<ll,ll> mp;
//deque<ll> deq;
//vector<ll> vll;
ll num[ten52];
//priority_queue<ll> pq;          //decreasing

int main(void)
{
    ll m,n,i,j,k=0,d,pre=0,now;
    string s,s1,s2;
    cin>>k>>n;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
        {
            d=n-i-j;
            if(d>=0 && d<=k)
                pre++;
        }
    }
    cout<<pre;
}
