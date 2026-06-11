#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long a[100003],b[100003],n,k,res=0;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i];
        if((a[i]&k)==a[i]){
        	res+=b[i];
		}
    }
    for(long long i=30;i>=0;i--){
        long long tmp=1<<i;
        if(k&tmp){
            long long f=(k^tmp)|(tmp-1);
            long long ans=0;
            for(int j=0;j<n;j++){
                if((a[j]&f)==a[j]){
                	ans+=b[j];
				}
            }
            res=max(res,ans);
        }
    }
    cout<<res<<endl;
    return 0;
}
/*

in:
7 14
10 5
7 4
11 4
9 8
3 6
6 2
8 9

out:
32

*/ 
/*
给定n个数，每个数有一个a值一个b值，一个k。
从所有的a中取数，这些数的按位或不能大于k，并且使得他们的b的和最大。
*/