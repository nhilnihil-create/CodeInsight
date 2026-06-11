#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	int n,sum=0,ans=0;
	cin>>n;
	vector<int> a(1000000);
	vector<int> b(1000000);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<1000000;i++){
		if(b[i]!=0){
			sum+=b[i]-1;
		}
	}
	ans=n-((sum+1)/2)*2;
	cout<<ans<<endl;
	return 0;
}