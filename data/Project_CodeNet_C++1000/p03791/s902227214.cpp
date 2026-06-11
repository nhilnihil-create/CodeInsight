#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <cstring>

#define MAX
#define INF
#define MOD 1000000007
#define MP make_pair
#define AA first
#define BB second
#define IS(X) cout << #X << " = " << X << endl;
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
LL a[100006];

int main() {
    a[1] = 1;
    for(int i = 2;i <= 100000;i++) {
        a[i] = i * a[i-1] % MOD;
    }
    int n;
    while(~scanf("%d",&n)) {
        int cnt = 0;
        LL ans = 1;
        for(int i = 0;i < n;i++) {
            int x;scanf("%d",&x);
            cnt ++;
            if(x < 2*cnt - 1) {
                ans *= cnt;
                ans %= MOD;
                cnt--;
            }
        }
        ans *= a[cnt];
        ans %= MOD;
        cout << ans << endl;
    }
}
