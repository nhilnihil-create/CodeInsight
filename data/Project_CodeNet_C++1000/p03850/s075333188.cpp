#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <time.h>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
#define MP make_pair
#define PB push_back
#define ms(a,b) memset((a),(b),sizeof(a))
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<Pii> Vii;
const int inf = 0x3f3f3f3f;
const LL INF = (1uLL << 63) - 1;
const LL mod = 1000000007;
const int N = 150 + 5;
const double Pi = acos(-1.0);
const int maxn = 200005;
using namespace std;
int n;
int num[maxn];
int pos[maxn];
LL suff[maxn];
char op[5];
int main() {
#ifdef local
    freopen("in","r",stdin);
#endif
    scanf("%d%d",&n,&num[0]);
    for(int i = 1; i < n; i++){
        scanf("%s%d",op,&num[i]);
        if(op[0] == '-')num[i] *= -1;
    }
    for(int i = n - 1; i >= 0; i--){
        suff[i] = suff[i+1] + abs(num[i]);
    }
    LL ans = -INF;
    LL res = 0;
    num[n] = -1;
    for(int i = 0; i < n; i++){
        if(num[i] < 0){
            int j = i + 1;
            LL ff = num[i];
            while(j <= n && num[j] >= 0)ff -= num[j++];
            res += ff;
            ans = max(res + suff[j],ans);
            res -= ff;
            res += num[i];
        }
        else res += num[i];
    }
    ans = max(res,ans);
    cout<<ans<<endl;
}
