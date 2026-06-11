#include <bits/stdc++.h>

using namespace std;

long long Q[1005];
int top = -1;

int main() {
    long long n, x, ans = 0;
    cin >> n >> x;
    if(n - x > x) {
        Q[++top] = x;
        Q[++top] = n - x;
        Q[++top] = x;
        ans += n;
    }
    else {
        Q[++top] = x;
        Q[++top] = n - x;
        ans += n;
    }
    while(Q[top]) {
        long long k = Q[top - 1] / Q[top];
        ans += 2 * k * Q[top];
        Q[top + 1] = Q[top - 1] - k * Q[top];
        top ++ ;
    }
    ans -= Q[top - 1];
    printf("%lld\n", ans);
    return 0;
}

//21:56:00
//思考时间有点长。对全新模型的建立/理解能力不够强。