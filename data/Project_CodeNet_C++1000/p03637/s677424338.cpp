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
    int N,A[100010]={},o=0,e4=0,f=0;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>A[i];
        if(A[i]%2==1)o++;
        if(A[i]%2==0&&A[i]%4!=0)f=1;
        if(A[i]%4==0)e4++;

    }

    o+=f;

    if(e4+1>=o){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}