#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
	
	int n;
	cin>>n;
	vector<int>a(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	sum=(sum)/n;
	int ans1=0,ans2=0,ans3=0;
	for(int i=0;i<n;i++){
		int temp=abs(a[i]-sum);
		ans1+=temp*temp;
	}
	sum+=1;
	for(int i=0;i<n;i++){
		int temp=abs(a[i]-sum);
		ans2+=temp*temp;
	}
	sum-=2;
	for(int i=0;i<n;i++){
		int temp=abs(a[i]-sum);
		ans3+=temp*temp;
	}
	cout<<min({ans1,ans2,ans3})<<endl;
	
	return 0;
}
