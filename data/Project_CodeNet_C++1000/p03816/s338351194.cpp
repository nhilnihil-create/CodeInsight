#include <bits/stdc++.h>
using namespace std;
int n,ans,sum;  
int a[100005],cishu[100005];  
void f(){
    for(int i=1;i<=sum;i++){
    	if(cishu[i]>1){
    		ans+=cishu[i]-1; 
		}else{
			continue;
		}
	}
    if(ans%2==1){
    	ans+=1;
	}  
    cout<<n-ans<<endl;  
    return ;  
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cishu[a[i]]++;
        if(a[i]>=sum){
        	sum=a[i];
		}
    }
    f();
    return 0;
}