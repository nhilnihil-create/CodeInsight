#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100003],ans;
int main(){
    cin>>n; 
	for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	if(i+1>a[i+1]){
            for(int j=i+1;a[j]==i;j++){
                ans^=1;
            }
            ans=(ans|(a[i]-i)&1);
            cout<<(ans?"First":"Second")<<endl;
            return 0;
        }
	}
    return 0;
}