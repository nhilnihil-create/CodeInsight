#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++){
    	cin >> vec.at(i);
    }
  	int n = 0;
  	int counter = 0;
  	while (n != 1){
    	n = vec.at(n) - 1;
    	counter += 1;
      	if (counter > N){
        	break;
        }
    }
  	if (counter > N){
    	cout << -1 << endl;
    }
  	else{
    	cout << counter << endl;
    }
}
