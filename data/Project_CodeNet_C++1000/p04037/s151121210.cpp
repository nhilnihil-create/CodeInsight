#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100002];
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)
        if(i+1>a[i+1]&&a[i]>=i)
		{
            int j=0;
            while(a[j+i+1]==i) j++;
            if((a[i]-i)%2==0&&j%2==0) printf("Second");
            else printf("First");   
    		return 0;
        }
    return 0;
}