#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int N;
	cin>>N;
	
	int maxA = 0,maxB = 0;
	
	for(int i=0;i<N;i++){
		int A,B;
		cin>>A>>B;
		if(maxA<A){
			maxA=A;
			maxB=B;
		}
	}
	
	cout<<maxA+maxB<<endl;
	
	return 0;
}