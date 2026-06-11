#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int> h;
bool isenough(int t){
	long long int x=0;
	for(int i=0;i<n;i++){
		x+=(max(h[i]-b*t,0)/(a-b))+(max(h[i]-b*t,0)%(a-b)!=0);
		if(x>t)return false;
	}
	if(x>t)return false;
	else{
		return true;
	}
}
int main(){
	
	cin>>n>>a>>b;
	h.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	int mx=INT_MIN;
	for(int i=0;i<n;i++){
		mx=max(mx,h[i]);
	}
	int n=mx/b;
	int st=0;
	int end=n+1;
	while(st<end){
		int mid=st+(end-st)/2;
		if(isenough(mid)){
			end=mid;
		}
		else{
			st=mid+1;
		}

	}
	cout<<st<<endl;
}