#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//int n,q,i,t,x,ansa[200005],ansb[200005],mna,mnb;
int a[200005];

set<int>::iterator it;
int main()
{
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(int i=2;i<=n;i++){
        if(a[i-1]+a[i]>x){
            ans+=a[i]+a[i-1]-x;
            if(a[i-1]>x){
                a[i]=0;
            }
            else{
                a[i]-=a[i]+a[i-1]-x;
            }

        }
	}
	cout<<ans<<endl;
}
