#include <bits/stdc++.h>
using namespace std;
const int m=1000000007;
int n,f[1000005];
int a;
int main(){
    cin>>n;
    while(0){
    	int ggg;
    	cin>>ggg;
    	cin>>ggg;cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
    	cin>>ggg;
	}
    f[n]=n;
    f[n-1]=(long long)n*n%m;
    for(int i=n-2;i>=1;i--){
        a=(a+f[i+3])%m;
        f[i]=f[i+1];
        f[i]=(f[i]+(long long)(n-1)*(n-1)%m)%m;
        f[i]+=a;
        f[i]%=m;
        f[i]+=i+1;
        f[i]%=m;
    }
    cout<<f[1]<<endl;
}