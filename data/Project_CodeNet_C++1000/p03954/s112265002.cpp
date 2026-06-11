#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000006, INF=1000000009;
long long a[N], b[N], t[N], n, u;
int main(){ ios_base::sync_with_stdio(false);
    cin>>n;n*=2;n--;
    for (int i=1; i<=n; i++)
      	cin>>a[i];
    int l=1, r=n;
    int k=n/2+1;
    while(l<r){
       	int mid=(l+r+1)/2;
    	for (int i=1; i<=n; i++)
     		if(a[i]>=mid)b[i]=1;
      		else 		 b[i]=0;
      	if(b[k]==b[k-1] || b[k]==b[k+1]){
			if(b[k])l=mid;
			else      r=mid-1;
		}
		else{
     		int x=k; while(b[x]!=b[x+1] && x<n)x++;
     		int y=k; while(b[y]!=b[y-1] && y>1)y--;
       		if((b[k]+min(x-k, k-y))%2)l=mid;
       		else r=mid-1;
       	}
    }
    cout<<l;
   	return 0;
}