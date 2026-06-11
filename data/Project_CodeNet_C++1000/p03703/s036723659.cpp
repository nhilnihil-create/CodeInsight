#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n;
LL K;
const int maxn = 2e5 + 5;
LL A[maxn];
pair<LL, int> pre[maxn];
int c[maxn];

int sum(int p){
    int res = 0;
    for(int i = p;i > 0;i -= i & -i){
        res += c[i];
    }
    return res;
}

void add(int p, int v){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += v;
    }
}


int main(){
    cin >> n;
    cin >> K;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &A[i]);
        A[i] -= K;
    }
    pre[0] = make_pair(0, 0);
    for(int i = 1;i <= n;i++){
        pre[i].first = pre[i - 1].first + A[i];
        pre[i].second = i;
    }
    sort(pre, pre + 1 + n);
    LL ans = 0;
    for(int i = 0;i <= n;i++){
        ans += sum(pre[i].second + 1);
        add(pre[i].second + 1, 1); 
    }
    cout << ans << endl;
    return 0;
}
