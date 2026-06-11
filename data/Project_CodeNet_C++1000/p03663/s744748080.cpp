#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define INF 0X3F3F3F3F3F3F3F3F
#define N 200005
#define M 200005
#define LL long long
#define FF(i, a, b) for(int i = a; i <= b; ++i)
#define RR(i, a, b) for(int i = a; i >= b; --i)
#define FJ(i, a, b) for(int i = a; i < b; ++i)
#define SC(x) scanf("%d", &x)
#define SCC(x, y) scanf("%d%d", &x, &y)
#define SCCC(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define SS(x) scanf("%s", x)
#define PR(x) printf("%d\n", x)
#define CL(a, x) memset(a, x, sizeof(a))
#define _P fd[rt]
#define _L fd[rt << 1]
#define _R fd[rt << 1 | 1]
#define MID int mid = ((l + r) >> 1)
#define lson rt<<1 ,l, mid
#define rson rt<<1 | 1, mi d + 1, r
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define MP make_pair
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-8;
inline void II(int &n){char ch = getchar(); n = 0; bool t = 0;
for(; ch < '0'; ch = getchar()) if(ch == '-') t = 1;
for(; ch >= '0'; n = n * 10 + ch - '0', ch = getchar()); if(t) n =- n;}
LL l[N], r[N];
int cnt = 0;
LL s = 0;
char c[10];
bool ok(int x){
    printf("? %lld", s * 10 + x);
    for(int i = cnt + 1; i <= 13; ++i) printf("9");
    puts("");
    fflush(stdout);
    scanf("%s", c);
    if(c[0] == 'N') return 0;
    else return 1;
}
bool fuck(LL p){
    for(; p % 10 == 0; p /= 10);
    if(p == 1) return 1;
    return 0;
}
const LL ha[17] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
bool solve(){
    for(int i = 0; i < 17; ++i){
        printf("? %lld\n", ha[i]);
        fflush(stdout);
        scanf("%s", c);
        if(c[0] == 'N') return 0;
    }
    return 1;
}
int main(){
    if(solve() == 1){
        puts("! 1");
        return 0;
    }
    puts("? 2");
    fflush(stdout);
    scanf("%s", c);
    if(c[0] == 'N'){
        while(1){
            cnt += 1;
            int l = 0, r = 9;
            if(cnt == 1) l = 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(ok(mid)) r = mid - 1;
                else l = mid + 1;
            }
            if(l == 0){
                if(fuck(s)){
                    bool p1, p2;
                    printf("? %lld\n", s * 10 - 1);
                    fflush(stdout);
                    scanf("%s", c);
                    p1 = c[0] == 'Y';
                    printf("? %lld\n", s * 100 - 1);
                    fflush(stdout);
                    scanf("%s", c);
                    p2 = c[0] == 'Y';
                    if(p1 == 0 && p2 == 1){
                        s = s * 10;
                        break;
                    }
                }else {
                    printf("? %lld\n", s * 10 - 1);
                    fflush(stdout);
                    scanf("%s", c);
                    if(c[0] == 'N') break;
                }
            }
            s = s * 10 + l;
        }
        printf("! %lld\n", s);
        fflush(stdout);
    }
    else {
    while(1){
        cnt += 1;
        int l = 0, r = 9;
        if(cnt == 1) l = 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(ok(mid)) r = mid - 1;
            else l = mid + 1;
        }
        if(l == 0){
            printf("? %lld\n", s * 10 - 1);
            fflush(stdout);
            scanf("%s", c);
            if(c[0] == 'N') break;
        }
        s = s * 10 + l;
    }
    printf("! %lld\n", s);
    fflush(stdout);
    }
    return 0;
}
