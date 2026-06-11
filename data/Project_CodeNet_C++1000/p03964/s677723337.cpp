#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long res1,res2;
	for (int i=0;i<n;i++){
		long long a,b;
		cin>>a>>b;
		if (i==0){
			res1=a,res2=b;
			continue;
		}
		long long t1=(res1+a-1)/a;
		long long t2=(res2+b-1)/b;
		res1=a*max(t1,t2);
		res2=b*max(t1,t2);
	}
	cout<<res1+res2<<endl;
	return 0;
}