#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(i+1>a[i+1]){
        	int ans=0;
            for(int j=i+1;a[j]==i;++j)ans^=1;
            ans|=(a[i]-i)&1;
            if(ans)puts("First");
            else puts("Second");
            return 0;
            
		}
	}
}