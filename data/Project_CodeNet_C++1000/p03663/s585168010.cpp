/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

bool ask(ll x) {
    printf("? %lld\n", x);
    fflush(stdout);
    char res[2];
    scanf("%s", res);
    if (res[0] == 'Y') return true;
    return false;
}

void answer(ll x) {
    printf("! %lld\n", x);
    fflush(stdout);
    exit(0);
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    ll num = 1;
    int k = -1;
    for (int i = 0; i <= 10; i++) {
        if (!ask(num)) {
            k = i;
            break;
        }
        num *= 10;
    }
    if (k == -1) {
        num = 1;
        while (!ask(num + 1)) {
            num *= 10;
        }
        answer(num);
    }
    ll res = 0;
    for (int i = 1; i < k; i++) {
        int left = 0, right = 9;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (ask(res * 10 + mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        res = res * 10 + left;
    }
    int temp = 0;
    for (int i = 9; i >= 0; i--) {
        if (!ask((res * 10 + i) * 10LL)) {
            temp = i + 1;
            break;
        }
    }
    res = res * 10 + temp;
    answer(res);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
