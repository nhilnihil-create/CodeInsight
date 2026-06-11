#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long arr[500];
    long long arr2[1001];
    long long MOD=1000000007;
    for(int i=0;i<1001;i++)arr2[i]=1;
    int ind=1;
    arr[0]=2;
    for(long long i=3;i<1000;i++){
    	bool ok=true;
    	for(int j=0;j<ind;j++){
    		if(i%arr[j]==0){
    			ok=false;
    			break;
    		}
    	}
    	if(ok)arr[ind++]=i;
    }
   // for(int i=0;i<ind;i++)cout<<arr[i]<<endl;
   // cout<<ind<<endl;
    long long n;
    cin>>n;
    
    if(n==1){cout<<1<<endl;return 0;}
    for(long long i=2;i<=n;i++){
    	
    	for(long long ind2=0, j=0;j<=i&&ind2<168;ind2++){
    		j=arr[ind2];
    		long long cnt=0;
    		long long cur=i;
    	//	cout<<j<<" "<<i<<" "<<ind2<<endl;
    		while(cur%j==0&&cur!=0){
    			cur=cur/j;
    			cnt=cnt+1;
    			//cout<<cnt<<" "<<cur<<endl;
    		}
    		arr2[j]+=cnt;
    		
    		//cout<<arr2[arr[j]]<<endl;
    	}
    }
    long long ans=1;
    for(int i=0;i<=n;i++){
    	ans=ans*arr2[i]%MOD;
    }
    cout<<ans<<endl;
    return 0;
}