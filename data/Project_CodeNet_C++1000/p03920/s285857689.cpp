#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int max = 0;
	for(;;){
		max++;
		if(max * (max + 1) / 2 > N) break;
	}
	int skip = max * (max + 1) / 2 - N;
	for(int i = 1; i <= max; i++){
		if(i == skip) continue;
		cout << i << endl;
	}
	return 0;
}
