#include<bits/stdc++.h>
using namespace std;

typedef long long ll;typedef vector<int> vi;typedef pair<int ,int > pii;typedef map<int,int>mii;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define el <<"\n"
#define newline printf("\n")
#define scd(x) scanf("%d",&x)
#define scdd(x,y) scanf("%d%d",&x,&y)
#define scddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scd(x) scanf("%ld",&x)
#define scdd(x,y) scanf("%ld%ld",&x,&y)
#define scddd(x,y,z) scanf("%ld%ld%ld",&x,&y,&z)
#define yo printf("YES\n")
#define noo printf("NO\n")
#define F first
#define S second
#define pb(a) push_back(a)
#define bg begin()
#define en end()
#define itr iterator
#define gcd(a,b) __gcd(a,b)
#define all(x) x.bg,x.en
int i;

int main()
{
    int x,y;
    scdd(x,y);
    int a[]={4,6,9,11},b[]={1,3,5,7,8,10,12};
    int n=sizeof(a)/sizeof(a[0]),m=sizeof(b)/sizeof(b[0]);
    bool u=false,v=false;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
            u=true;
        if(a[i]==y)
            v=true;
    }
    if(u&&v)
        cout<<"Yes" el;
    else
    {
        u=false,v=false;
        for(i=0;i<m;i++)
    {
        if(b[i]==x)
            u=true;
        if(b[i]==y)
            v=true;
    }
    if(u&&v)
        cout<<"Yes" el;
    else
        cout<<"No" el;
    }
    return 0;
}

