#include<bits/stdc++.h>
using namespace std;
long long int c[55][55],v[55];
int n,A,B;
long long int sum, num, val;
int main(){
	cin>>n>>A>>B;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=i; j++)
			c[i][j] = j==0||j==i?1:c[i-1][j]+c[i-1][j-1];
	for(int i=0; i<n; i++)
		cin>>v[i];
	sort(v,v+n);
	reverse(v,v+n);
	sum = 0;
	num = 1;
	val = 0;
	for(int i=A; i<=B; i++){
		long long int tot = 0;
		long long int AA = 0, BB = 0;
		for(int j=0; j<n; j++)
			if(v[j] == v[i-1])AA++;
		for(int j=0; j<i; j++){
			tot += v[j];
			if(v[j] == v[i-1])BB++;
		}
		long long int qq = c[AA][BB];
		if(tot * num > sum * i){
			sum = tot;
			num = i;
			val = qq;
		}else
		if(tot * num == sum * i){
			val += qq;
		}
	}
	printf("%lf\n", (double)(sum) / num);
	fflush(stdout);
	cout<<val<<endl;
	return 0;
}
