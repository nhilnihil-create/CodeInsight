#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;
	int n=s.size()-1;
	long long ans=0;

	for(int i=0;i<(1<<n);i++){
		bitset<9> bits=i;
		long long pre=0;
		long long keta=1;

		for(int j=n;j>0;j--){
			pre+=(s.at(j)-'0')*keta;

			if(bits.test(j-1)){
				keta=1;
			}else{
				keta*=10;
			}
		}

		pre+=(s.at(0)-'0')*keta;

		ans+=pre;
	}

	cout<<ans<<endl;

	return 0;
}
