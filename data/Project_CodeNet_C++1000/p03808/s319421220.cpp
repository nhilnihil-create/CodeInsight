#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N;
	cin >> N;
	vector<long long> A(N);
	for(auto &a:A)cin >> a;
	
	long long sum=accumulate(A.begin(),A.end(),0LL);
	if(sum%((N*N+N)/2LL)!=0LL){
		cout << "NO" << endl;
		return 0;
	}
	long long C=sum/((N*N+N)/2LL);
	
	if(*min_element(A.begin(),A.end())<C){
		cout << "NO" << endl;
		return 0;		
	}
	
	long long c=0LL;
	for(auto i=0;i<N;i++){
		long long L=A[i],R;
		if(i==N-1)R=A[0];
		else R=A[i+1];
			
		if((C-(R-L))%N!=0LL){
			cout << "NO" << endl;
			return 0;
		}
		c+=(C-(R-L))/N;
	}
	//cout << C << " " << c << endl;
	
	if(c==C)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}