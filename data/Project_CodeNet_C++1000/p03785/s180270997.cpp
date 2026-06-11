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
    int N,C,K,T[100010]={},ans=0,pcnt=0,et=0;

    cin>>N>>C>>K;

    for(int i=0;i<N;i++){
        cin>>T[i];
    }

    sort(T,T+N);

    for(int i=0;i<N;i++){
        if(et==0||pcnt==C||T[i]>et){
            et=T[i]+K;
            pcnt=1;
            ans++;
        }else{
            pcnt++;
        }
    }

    cout<<ans<<endl;

    return 0;
}