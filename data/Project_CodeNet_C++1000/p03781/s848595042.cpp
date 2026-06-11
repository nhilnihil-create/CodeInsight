#include<iostream>
#include<vector>
using namespace std;

int main(){
	int X; cin >> X;
	vector<int> cul;
	cul.push_back(0);

	int max = 0;
	for(int i = 1; i <= X; ++i){
		cul.push_back(cul[i-1]+i);
		if(cul[i-1] < X && X <= cul[i]){
			if(max < i) max = i;
		}

		if(cul[i] > X) break;
	}

	cout << max << endl;

	return 0;
}
