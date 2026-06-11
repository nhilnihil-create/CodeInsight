#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000


int main(){
	
	int N;
	cin>>N;
	N = 2*N-1;
	
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
		a[i]--;
	}
	
	int ok = 0;
	int ng = N;
	
	while(ng-ok>1){
		int mid = (ok+ng)/2;
		vector<bool> B(N);
		for(int i=0;i<N;i++){
			if(mid<=a[i])B[i]=true;
			else B[i]=false;
		}
		int mini = 1000000;
		bool F = false;
		for(int i=0;i<N;i++){
			if((i!=0&&B[i]==B[i-1])||(i!=N-1&&B[i]==B[i+1])){
				int t = abs(i-N/2);
				if(mini>t){
					mini = t;
					F = B[i];
				}
			}
		}
		if(mini==1000000){
			F = B[N/2];
			int t = ((N-1)/2)%2;
			if(F){
				if(t==0)ok = mid;
				else ng = mid;
			}
			else{
				if(t==0)ng = mid;
				else ok = mid;
			}				
		}
		else{
			if(F)ok = mid;
			else ng = mid;
		}
	}
	
	cout<<ok+1<<endl;
	
	return 0;
}
