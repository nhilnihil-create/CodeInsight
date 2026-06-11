#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    string a,b;
    cin >> a >> b;
    int aa = a.size(),bb = b.size();

    for (int i=0;i<bb;++i){
        putchar(a[i]);
        putchar(b[i]);
    }

    if (aa != bb){
        putchar(a[bb]);
    }

    return 0;
}
