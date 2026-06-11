#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;

ll dp[101][101];

void nck(ll n,ll k){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j-1>=0){
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
}

int main(){
	ll n,a,b; cin >> n >> a >> b;
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			dp[i][j]=0;
		}
	}
	nck(n+1,n+1);
	ll v[n];
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	sort(v,v+n);
	reverse(v,v+n);
	ll s[n];
	s[0]=0;
	for(int i=0;i<n;i++){
		s[i+1]=s[i]+v[i];
	}
	printf("%.8f\n",(double)s[a]/a);
	ll cnt=0;
	for(int i=a;i<=b;i++){
		if(s[a]*i==s[i]*a){
			if(i==n){
				cnt++;
				continue;
			}
			ll tmp=0,idx=-1;
			for(int j=0;j<n;j++){
				if(v[i]<v[j])idx=j;
				if(v[i]==v[j])tmp++;
			}
			if(tmp==1){
				cnt++;
				break;
			}
			cnt+=dp[tmp][i-idx-1];
		}
		else{
			break;
		}
	}
	cout << cnt << endl;
}