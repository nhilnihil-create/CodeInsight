#include<iostream>
#include<algorithm>
using namespace std;
const int N=501;
int a[501*501],X[501];
int c[N],cnt[N];
int pos[N][N],num[N];
int n;
bool cmp(int a,int b)
{
	return X[a]<X[b];
}
bool check()
{
    for(int i=1;i<=n*n;i++)
        pos[a[i]][++num[a[i]]]=i;
    for(int i=1;i<=n;i++)
        if(pos[i][i]!=X[i]) return false;
    return true;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
		cin>>X[i],c[i]=i,a[X[i]]=i,cnt[i]=i-1;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n*n;i++)
        if(!a[i])
	        for(int j=1;j<=n;j++)
	            if(cnt[c[j]])
	            {
					a[i]=c[j];cnt[c[j]]--;break;
				}
    for(int i=1;i<=n;i++)
		cnt[i]=n-i;
    for(int i=n*n;i>=1;i--)
        if(!a[i])
        	for(int j=n;j>=1;j--)
            	if(cnt[c[j]])
				{
					a[i]=c[j];cnt[c[j]]--;break;
				}
    if(check())
    {
        cout<<"Yes\n";
        for(int i=1;i<=n*n;i++)
            cout<<a[i]<<" ";
    }
    else cout<<"No";
    return 0;
}