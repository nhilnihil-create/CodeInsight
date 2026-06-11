#include <bits/stdc++.h>
using namespace std;

long long int a[212345], pos[212345], resp;
int n;


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), pos[a[i]] = i;
    set < int > s;
    s.insert(0);
    s.insert(n+1);
    for(int i = 1; i <= n; i++){
        int l, r;
        s.insert(pos[i]);
        set<int>::iterator it = s.find(pos[i]);
        r = *(++it) - pos[i];
        --it;
        l = pos[i] - *(--it);
        resp += (long)i*r*l;
    }
    printf("%lld\n", resp);
    
    return 0;
}