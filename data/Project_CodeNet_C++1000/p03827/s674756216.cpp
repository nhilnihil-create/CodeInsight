#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string S;
	cin>>N;
	cin>>S;
	int nx=0;
	int x=0;
	for(int i=0;i<=S.length();i++){	
		x=max(nx,x);
		if(S[i]=='I'){
			nx+=1;
		}else{
			nx-=1;
		}
	}
	cout<<x<<endl;
}