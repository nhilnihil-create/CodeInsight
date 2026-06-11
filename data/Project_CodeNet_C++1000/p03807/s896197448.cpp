#include "bits/stdc++.h"
using namespace std;

int main(){
	int N;
	cin >> N;
	int k=0,g=0;
	for(int i=0;i<N;i++){
		int x;
		cin >> x;
		if(x%2==0) g++;
		else k++;
	}
	if(k%2==0) cout << "YES" <<endl;
	else cout << "NO" <<endl;
}
