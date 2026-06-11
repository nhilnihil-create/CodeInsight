#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;cin>>n;
	long long a,b;cin>>a>>b;
	vector<long long> h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	sort(h.begin(),h.end(),greater<long long>());
	long long c=a-b;
	long long right=1;
	for(int i=0;i<9;i++){
		right*=10;
	}
	long long left=0;
	while(right-left>1){
		long long center=(right+left)/2;
		int flag=1;
		long long count=0;
		for(int i=0;i<n;i++){
			long long hp=h[i];
			hp-=b*center;
			if(hp>0){
				count+=(hp-1)/c+1;
			}
		}
		if(count>center)flag=0;

		if(flag){
			right=center;
		}else{
			left=center;
		}
	}
	cout<<right<<endl;

	return 0;
}
