#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	long long n,h=0,w=0;
	cin >> n;
	
	vector<long long> a(n,0);
	
	for(long long i=0;i<n;i++){
		cin >> a[i];
	}
	
	sort(a.begin(),a.end(),greater<long long>());
	
	for(long long i=1;i<n;i++){
		if(h==0){
			if(a[i]==a[i-1]){
				h=a[i];
				a[i]=0;
				a[i-1]=0;
				continue;
			}
		}
		if(w==0){
			if(a[i]==a[i-1]){
				w=a[i];
				cout << h*w << endl;
				return 0;
			}
		}
	}
	
	cout << "0" << endl; 
	return 0;
}
