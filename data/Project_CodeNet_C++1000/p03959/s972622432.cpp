#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N;
	cin>>N;
	
	vector<int> T(N),A(N);
	
	for(int i=0;i<N;i++)cin>>T[i];
	for(int i=0;i<N;i++)cin>>A[i];
	
	vector<int> l1(N),r1(N),l2(N),r2(N);
	
	for(int i=0;i<N;i++){
		if(i==0){
			l1[i] = T[i];
			r1[i] = T[i];
		}
		else{
			if(T[i]==T[i-1]){
				l1[i] = 1;
				r1[i] = T[i];
			}
			else{
				l1[i] = T[i];
				r1[i] = T[i];
			}
		}
	}
	
	reverse(A.begin(),A.end());
	
	for(int i=0;i<N;i++){
		if(i==0){
			l2[N-1-i] = A[i];
			r2[N-1-i] = A[i];
		}
		else{
			if(A[i]==A[i-1]){
				l2[N-1-i] = 1;
				r2[N-1-i] = A[i];
			}
			else{
				l2[N-1-i] = A[i];
				r2[N-1-i] = A[i];
			}
		}
	}
	
	int ans = 1;
	
	for(int i=0;i<N;i++){
		int L = max(l1[i],l2[i]);
		int R = min(r1[i],r2[i]);
		if(L>R){
			cout<<0<<endl;
			return 0;
		}
		
		ans = mod(ans * (R-L+1));
	}
	
	cout<<ans<<endl;
	
	return 0;
}