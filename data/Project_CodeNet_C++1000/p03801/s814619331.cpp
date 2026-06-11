#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int n;
typedef long long LL;
const int maxn = 1e5 + 5;

pair<LL, int> a[maxn];
LL cnt[maxn];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i].first);
        a[i].first *= -1;
        a[i].second = i;
    }
    a[0] = make_pair(0, 0);
    sort(a, a + n + 1);
    set<int> s;
    s.insert(a[0].second);
    LL now = -a[0].first;
    for(int i = 1;i <= n;i++){
        if(-a[i].first != now){
            int id = *s.begin();
            cnt[id] += 1LL * s.size() * (now + a[i].first);
        }
        s.insert(a[i].second);
        now = -a[i].first;
    }
    for(int i = 1;i <= n;i++){
        printf("%lld\n", cnt[i]);
    }
    return 0;
}
