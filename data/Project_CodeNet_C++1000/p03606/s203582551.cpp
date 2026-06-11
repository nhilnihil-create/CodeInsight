#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;
	cin >> N;

	int A , B;
	vector<int> now(2*N);

	for(int i = 0; i < 2*N; i++){
		cin >> now.at(i);

		if(i%2==1){
			B += now.at(i);
		}
		else{
			A += now.at(i);
		}
	}

	cout << B - A + N <<endl;

}