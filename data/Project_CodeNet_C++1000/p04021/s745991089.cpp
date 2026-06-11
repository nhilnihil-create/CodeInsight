#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main(){
    int n;
    scanf("%d",&n);
    ii a[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    sort(a,a+n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += (a[i].second^i)&1;
    }
    printf("%d",ans/2);
}
