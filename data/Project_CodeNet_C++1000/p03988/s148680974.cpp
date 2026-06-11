#include<bits/stdc++.h>
#define reg register
#define maxn 1001
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int n, a[maxn], b[maxn];
int main(){
    n = read();
    for(int i = 1; i <= n; i++) 
    a[i] = read(), b[a[i]]++;
    sort(a + 1, a + n + 1);
    for(int i = a[n]; i >= 0; i--){
        int x = max(a[n] - i, i);
        b[x]--; if(b[x] < 0) {
            cout << "Impossible";return 0;
        }
    }
    for(int i = 1; i <= (a[n] + 1) / 2; i++)
    {
        if(b[i]) {cout << "Impossible\n"; return 0;}
    }
    cout << "Possible"; return 0;
}