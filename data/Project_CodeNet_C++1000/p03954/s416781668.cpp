#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
#define ll long long
#define inf int(2e5+7)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define l(s) s.size()
using namespace std;
int n,a[inf];
inline bool check(const int k)
{
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))
		return 1;
    if((a[n-1]>k&&a[n]>k)||(a[n]> k&&a[n+1]> k))
		return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))
			return 1;
        if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))
			return 0;
    }
    return a[1]<=k;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n<<1;i++)
		scanf("%d",a+i);
    int l=1,r=(n<<1)-1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))
			r=mid;
        else
			l=mid+1;
    }
    printf("%d",l);
    return 0;
}