#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long x,long y){
    if(y==0)return x;

    return gcd(y,x%y);
}
long long lcm(long x,long y){
    return x*y/gcd(x,y);
}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main()
{
    long long ans=0;
    int N,T,t[200010]={};
    cin>>N>>T;

    for(int i=1;i<=N;i++){
        cin>>t[i];
        ans+=T;

        if(i!=1){
            ans-=max(T-(t[i]-t[i-1]),0);
        }
    }

    cout<<ans<<endl;

    return 0;
}