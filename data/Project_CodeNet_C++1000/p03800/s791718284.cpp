#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
char str[maxn];
int ans[maxn];
int main() {
    //freopen(".in", "r", stdin);
    int n;scanf("%d",&n);
    scanf("%s",str);
    bool isok = false;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            memset(ans, 0, sizeof(ans));
            ans[n - 1]=i,ans[0]=j;
            for (int k = 0; k < n - 2; k++) {
                int pre = (k - 1 + n) % n;
                int nxt = (k + 1) % n;
                if (ans[k] == 1) {
                    if (str[k] == 'o') {
                        ans[nxt] = ans[pre];
                    } else {
                        ans[nxt] = 3 - ans[pre];
                    }
                } else {
                    if (str[k] == 'x') {
                        ans[nxt] = ans[pre];
                    } else {
                        ans[nxt] = 3 - ans[pre];
                    }
                }
            }
            bool success = true;
            for (int k = 0; k < n; k++) {
                int pre = (k - 1 + n) % n;
                int nxt = (k + 1) % n;
                if (ans[k] == 1) {
                    if (str[k] == 'o' && ans[pre] == ans[nxt]) ;
                    else if (str[k] == 'x' && ans[pre] == 3 - ans[nxt]) ;
                    else {
                        success = false;
                        break;
                    }
                } else {
                    if (str[k] == 'x' && ans[pre] == ans[nxt]) ;
                    else if (str[k] == 'o' && ans[pre] == 3 - ans[nxt]) ;
                    else {
                        success = false;
                        break;
                    }
                }
            }
            if (success) {
                isok = true;
                break;
            }
        }
        if (isok) break;
    }
    if (!isok) return 0 * puts("-1");
    else {
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) printf("S");
            else printf("W");
        }
    }
    return 0;
}

