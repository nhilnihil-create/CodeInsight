#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define ROF(i,a,b) for(int i = (a);i>=(b);i--)
#define MST(a,x) memset(a,x,sizeof(a))
#define ll long long
#define PB push_back
#define PH push
#define MP make_pair
#define FT first
#define SD second
#define N 100005
#define M 305
#define INF 1000000007
#define MOD 1000000007
#define MOD2 1000000009
#define eps 1e-14
using namespace std;
int a[N];
vector<int>ans;
const bool cmp(const int &x,const int &y)
{
    return x%2>y%2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        ans.clear();
        int x,y;
        x = y = 0;
        FOR(i,1,m)
        {
            cin>>a[i];
            if(a[i]%2)x++;
            else y++;
        }

        if(x>2)printf("Impossible\n");
        else
        {
            sort(a+1,a+m+1,cmp);
            if(m>1)swap(a[2],a[m]);
            FOR(i,1,m)printf("%d ",a[i]);
            printf("\n");
            if(a[1]>1)ans.PB(a[1]-1);
            FOR(i,2,m-1)ans.PB(a[i]);
            if(m>=2)ans.PB(a[m]+1);
            else ans.PB(1);

            printf("%d\n",ans.size());
            for(auto u:ans)printf("%d\n",u);
        }
    }
    return 0;
}
