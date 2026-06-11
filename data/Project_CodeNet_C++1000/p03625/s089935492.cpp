#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n,p[100000],len,l1,l2,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=len;i++)cout<<a[i]<<" ";
	for(int i=n;i>=1;i--){
	    if(a[i]==a[i-1]){
		    p[++t]=a[i];
			i--;
			if(t==2)break; 
		} 
	}
	cout<<p[1]*p[2];
    return 0;
}