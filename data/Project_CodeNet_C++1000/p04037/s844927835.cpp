#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7; int n,ans,a[N];
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
    scanf("%d",&n); for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(i+1>a[i+1]){
            for(int j=i+1;a[j]==i;j++) ans^=1; ans|=(a[i]-i)&1;
			if(ans) puts("First"); else puts("Second"); break;
        }
    return 0;
} 