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
    long long x,y,mx,my,ans=1000000000000;

    cin>>x>>y;
    mx=-x;
    my=-y;

    if(y-x>=0){
        ans=min(ans,y-x);
    }

    if(y-mx>=0){
        ans=min(ans,y-mx+1);
    }

    if(my-x>=0){
        ans=min(ans,my-x+1);
    }

    if(my-mx>=0){
        ans=min(ans,my-mx+2);
    }

    cout<<ans<<endl;

    return 0;
}