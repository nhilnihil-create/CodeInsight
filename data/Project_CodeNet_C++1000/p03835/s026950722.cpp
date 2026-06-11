//sum 3 int
#include <bits/stdc++.h>
using namespace std;
long long n,m,k,s,tmp,sum=0;
char r1,r2,op;
int main(){
	cin>>k>>s;
	for (int i=0;i<=k;i++){
		for (int j=0;j<=k;j++){
			long long tar=s-i-j;
			if (tar>=0 && tar<=k) sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}