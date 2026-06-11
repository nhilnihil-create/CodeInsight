#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;

int main(void){
	int digit=0;
	ll res=1;
	for(;digit<10;digit++){
		printf("? %lld\n",res);
		fflush(stdout);
		string str;
		cin >> str;
		if(str=="N")break;
		res*=10LL;
	}
	if(digit==10){
		res=1;
		for(int i=0;i<10;i++){
			printf("? %lld\n",res+1LL);
			fflush(stdout);
			string str;
			cin >> str;
			if(str=="Y"){
				printf("! %lld\n",res);
				fflush(stdout);
				return 0;
			}
			res*=10LL;
		}
		return 0;
	}
	res=0;
	for(int i=0;i<digit;i++){
		int l=0,r=10;
		if(i==0)l=1;
		res*=10LL;
		while(l+1<r){
			int mid=(l+r)/2;
			ll rr2=(ll)res+mid;
			for(int j=i;j<digit;j++){
				rr2*=10LL;
			}
			printf("? %lld\n",rr2);
			fflush(stdout);
			string str;
			cin >> str;
			if(str=="Y"){
				r=mid;
			}else{
				l=mid;
			}
		}
		res+=(ll)l;
	}
	printf("! %lld\n",res+1LL);
	fflush(stdout);
	return 0;
}