#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

template<typename T>
void read(T &n){
    n = 0;
    T f = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') f = -1, c = getchar();
    while(isdigit(c)) n = n*10+c-'0', c = getchar();
    n *= f;
}

int a[MAX];

int main()
{
    int T, n;
//    cin >> T;
//    while(T--){
        read(n);
        int l = n, r = 0;
        for(int i = 1; i <= n; i++){
            read(a[i]);
            l = min(l, a[i]);
            r = max(r, a[i]);
        }
        if(r-l > 1) puts("No");
        else if(r == l+1){
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] == l) cnt++;
            }
            if(cnt <= l && r <= cnt+(n-cnt)/2) puts("Yes");
            else puts("No");
        }
        else{
            if(l+1 == n) puts("Yes");
            else if(l*2 <= n) puts("Yes");
            else puts("No");
        }
//    }

    return 0;
}