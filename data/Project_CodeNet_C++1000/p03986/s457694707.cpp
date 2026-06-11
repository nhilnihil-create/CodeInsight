#include <bits/stdc++.h>
using namespace std;

int main(){
	string X;
	cin >> X;
	int remove=0;
	int N=X.size();
	int s=0;
	for(int i=0;i<N;i++){
		if(X[i]=='S')s++;
		else if(s>0){
			remove+=2;
			s--;
		}
	}
	cout << N-remove << endl;
	return 0;
}