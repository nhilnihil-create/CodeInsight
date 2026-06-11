#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define ls rt<<1
#define rs rt<<1|1
typedef long long ll;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

ll a, b, x;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin>>a>>b>>x;
    if(a==0)    cout<<((b/x) + 1);
    else    cout<<((b/x) - (a-1)/x);
    return 0;
}