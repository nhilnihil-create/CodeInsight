#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, a[nmax];
unordered_map<int,int>mp;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        mp[a[i]] = i;
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for (int i=n;i>=1;--i){
        int poz = mp[a[i]];
        if (abs((i-poz)%2) == 1){
            ++ans;
        }
    }
    cout<<ans/2<<'\n';
    return 0;
}
