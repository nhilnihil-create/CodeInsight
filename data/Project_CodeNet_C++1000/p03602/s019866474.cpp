#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pl;
int n;
ll a[303][303];
const ll inf = 10000000000000;
priority_queue<pl, vector<pl>, greater<pl>> pq;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            pq.emplace(a[i][j], pii(i,j));
            ans += a[i][j];
        }
    }
    int flag = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int x = p.second.first;
        int y = p.second.second;
        ll d = inf;
        for(int i=1;i<=n;i++){
            if(i!=x && i!=y)d = min(d, a[x][i] + a[i][y]);
        }
        if (p.first > d){
            flag = 1;
            break;
        }
        else if (p.first == d){
            ans -= d;
        }
    }
    printf("%lld\n", flag ? -1 : ans);
}
