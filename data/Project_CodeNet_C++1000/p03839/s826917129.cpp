#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> brojevi(n);
	vector<long long > sume(n);
	vector<long long> psume(n);
	cin>>brojevi[0];
	sume[0]=brojevi[0];
	if(brojevi[0]>=0) psume[0]=brojevi[0];
	for(int i=1;i<n;i++){
		cin>>brojevi[i];
		sume[i]=sume[i-1]+brojevi[i];
		psume[i]=psume[i-1]+brojevi[i];
		if(psume[i]<psume[i-1]) psume[i]=psume[i-1];
	}
	long long sol=0;
	long long temp=0;
	for(int i=0;i<=n-k;i++){
		temp=0;
		if(i>0){
			temp+=psume[i-1];
		}
		
		 temp+=psume[psume.size()-1]-psume[i+k-1];
		if(i>0){
			if(sume[i+k-1]-sume[i-1]>0) temp+=sume[i+k-1]-sume[i-1];
		}
		else{
			if(sume[i+k-1]>0) temp+=sume[i+k-1];
		}
		if(temp>sol) sol=temp;
	}
	cout<<sol;
}