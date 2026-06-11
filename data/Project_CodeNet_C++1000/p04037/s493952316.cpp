#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
int n,a[100005];
bool cmp(const int x,const int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(a[i+1]<i+1){
            int ans=0;
            for(int j=i+1;a[j]==i;j++)ans^=1;
            ans|=(a[i]-i)%2;
            if(ans>0)printf("First");
            else printf("Second");
            exit(0);
    }
    return 0;
}