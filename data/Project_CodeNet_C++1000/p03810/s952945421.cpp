#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
const int MAXN = 200010;
int a[MAXN], n;
bool play()
{
    int cnt = 0, x = 0;
    for(int i = 0; i < n; i++) if(a[i]&1) cnt++, x = i;
    if((n - cnt) & 1) return true;
    if(cnt > 1) return false;
    if(a[x] == 1) return false;
    a[x] -= 1;
    int g = a[0];
    for(int i = 1; i < n; i++) g = __gcd(g, a[i]);
    for(int i = 0; i < n; i++) a[i] /= g;
    return !play();
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    if(n == 1) puts(a[0]&1 ? "Second":"First");
    else puts(play() ? "First" : "Second");

    return 0;
}
