#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200001];
bool checx(int x)
{
    if((a[n-1]<=x&&a[n]<=x)||(a[n]<=x&&a[n+1]<=x))return 1;
    if((a[n-1]> x&&a[n]> x)||(a[n]> x&&a[n+1]> x))return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=x&&a[n+i+1]<=x)||(a[n-i]<=x&&a[n-i-1]<=x))return 1;
        if((a[n+i]> x&&a[n+i+1]> x)||(a[n-i]> x&&a[n-i-1]> x))return 0;
    }
    return a[1]<=x;
}

int main(){
    cin>>n;
    for(int i=1;i<n<<1;i++)cin>>a[i];
    int l=1,r=(n<<1)-1;
    while(l<r)
	{
        int mid=(l+r)/2;
        if(checx(mid))r=mid;
        else l=mid+1;
    }
    cout<<l;
}
