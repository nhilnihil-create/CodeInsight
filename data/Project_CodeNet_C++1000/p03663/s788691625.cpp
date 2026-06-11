#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
LL N = 123;

bool cal(LL cur) {
     string s1 = to_string(cur), s2 = to_string(N);
     if (cur <= N) {
        if (s1 <= s2) return true;
        else return false;
     } else {
        if (s1 > s2) return true;
        else return false;
     }
}

bool check(LL cur) {
     printf("? %lld\n", cur);
     fflush(stdout);
     char c;
     scanf(" %c", &c);
     if (c == 'Y') {
        //printf("Y %lld\n", cur);
        return true;
     } else {
        //printf("N %lld\n", cur);
        return false;
     }
}

int main() {
    //scanf("%lld", &N);
    LL cur = 10, dig = 1;
    bool OK = true;
    for (int i = 2; i <= 10; i++) {
        if (!check(cur)) {
           //printf("cur = %lld\n", cur);
           dig = i - 1;
           OK = false;
           break;
        }
        cur *= 10;
    }
    if (OK) {
       LL tmp = 9, ans = 1;
       for (int i = 1; i <= 10; i++) {
           if (check(tmp)) {
              printf("! %lld\n", ans);
              fflush(stdout);
              return 0;
           }
           ans *= 10;
           tmp = tmp * 10 + 9;
       }
    } else {
       //printf("ans dig = %lld\n", dig);
       LL l = (LL)pow(10, dig), r = (LL)pow(10, dig + 1);
       while (l < r) {
             LL mid = (l + r) / 2;
             if (check(mid)) r = mid;
             else l = mid + 1;
       }
       printf("! %lld\n", l / 10);
       fflush(stdout);
    }
    return 0;
}
