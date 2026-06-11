#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	int n,k;
	vector<bool> bad(10,false);
	cin>>n>>k;
	for(int i=0;i<k;++i){
		int d;
		cin>>d;
		bad[d]=true;
	}
	
	vector<bool> good(100009,true);
	for(int i=1;i<=100000;++i){
		int n=i;
		while(n){
			int d=n%10;
			n/=10;
			if(bad[d])
				good[i]=false;
		}
	}
	for(int i=n;i<=100000;++i)
		if(good[i]){
			cout<<i<<"\n";
			break;
		}

	return 0;
}
