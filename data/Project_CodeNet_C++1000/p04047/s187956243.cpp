#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <map>　　　　　　
#include <iostream>
#include <queue>
#include <set>　　　　　　
#include <string>　　　　　
#include <vector>
using namespace std;
int n,a[210],ans=0;
int main(){
    scanf("%d",&n);
    for (int i=1; i<=2*n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    for (int i=1; i<=n; i++)
        ans+=a[i*2-1];
    printf("%d\n",ans);
}