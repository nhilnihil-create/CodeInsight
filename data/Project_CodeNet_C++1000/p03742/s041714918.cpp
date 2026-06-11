#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    int n;
    ll x,y;
    int t;
   
    
        scanf("%lld%lld",&x,&y);
        if(max(x,y)-min(x,y)>=2)printf("Alice\n");
        else printf("Brown\n");
    
    return 0;
}
