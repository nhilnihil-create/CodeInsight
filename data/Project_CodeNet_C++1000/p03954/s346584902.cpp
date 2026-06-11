#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int now[200005];
//bool check(int x){
//	int k,ans[2];
//	ans[0]=0;	ans[1]=0;
//	for(k=1;k<n+n;k++)	now[k]=a[k]>=x;

//	for(k=n-2;k>0;k--)		if(now[k]==now[k+1]){ans[now[k]]=n-k;break;}
//	for(k=n+2;k<n+n;k++)	if(now[k]==now[k-1]){ans[now[k]]=k-n;break;}
//	if(ans[0]&&ans[1])	return ans[0]<ans[1];
//	if(ans[1])	return 1;
//	if(ans[0])	return 0;
//	if(ans[0]==0&&ans[1]==0)	return now[1];	
//}
inline bool check(int x){
	int k;
	for(k=1;k<n+n;k++)	now[k]=a[k]>=x;
	if(now[n]==now[n-1]||now[n]==now[n+1])	return now[n];    
    for(k=1;k<n-1;k++){
        if((now[n+k]&&now[n+k+1])||(now[n-k]&&now[n-k-1]))return 1;
        if(!(now[n+k]||now[n+k+1])||!(now[n-k]||now[n-k-1]))return 0;
    }
    return now[1];
}
int main(){
	int k;
	cin>>n;
	for(k=1;k<=n+n-1;k++)	cin>>a[k];
	int l=1,r=n+n-1,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid))	l=mid;
		else			r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}