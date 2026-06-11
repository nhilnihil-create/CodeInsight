#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	int n,x;
	cin>>n>>x;
	vector<int> box(n);
	for(int i=0;i<n;i++) cin>>box.at(i);

	long long cnt=0;

	for(int i=0;i<n-1;i++){
		if(box.at(i)+box.at(i+1)>x){
			cnt+=box.at(i)+box.at(i+1)-x;
			box.at(i+1)-=box.at(i)+box.at(i+1)-x;

			if(box.at(i+1)<0){
				box.at(i)+=box.at(i+1);
				box.at(i+1)=0;
			}
		}
	}

	cout<<cnt<<endl;

	return 0;
}
