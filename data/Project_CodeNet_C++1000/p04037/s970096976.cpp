#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 100003;
template<typename T>
inline void read(T &x){
    int ch = getchar(); x = 0;
    for(;ch < '0' || ch > '9';ch = getchar());
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + ch - '0';
}
int n, a[N];
int main(){
    read(n);
    for(Rint i = 1;i <= n;++ i) read(a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for(Rint i = 1;i <= n;++ i)
        if(a[i + 1] < i + 1){
            int j = 0;
            for(;a[j + i + 1] == i;++ j);
            if((a[i] - i & 1) || (j & 1)) puts("First");
            else puts("Second");
            return 0;
        }
}