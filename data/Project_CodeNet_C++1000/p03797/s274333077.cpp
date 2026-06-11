#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	long long  N,M;
	cin>>N>>M;
	if(N>=M/2){
		cout<<M/2<<endl;
	}
	else{
		cout<<N+(M-2*N)/4<<endl;
	}
    return 0;
}