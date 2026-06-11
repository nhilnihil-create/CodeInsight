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
    long long K,N,a,b;
    map<long long,long long> mp;
    cin>>N>>K;

    for(long long i=1;i<=N;i++){
        cin>>a>>b;

        mp[a]+=b;
    }

    long long sum=0;

    for(auto itr = mp.begin(); itr!=mp.end();itr++){

        sum+=itr->second;

        if(sum>=K){
            cout<<itr->first<<endl;
            return 0;
        }
    }

    return 0;
}