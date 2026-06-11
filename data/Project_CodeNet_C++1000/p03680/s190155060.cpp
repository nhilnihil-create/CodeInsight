#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	cin >> N;
  	vector<int> light(N);
    for(int i = 0; i < N ; i++){
    	cin >> light.at(i);
    }
  	int next = 1;
    bool check = false;
  	int counter = 0;
  	for(int i = 0; i < N ; i++){
        counter++;
    	next = light.at(next - 1);
      	if(next == 2){
        	check = true;
          	break;
        }
    }
  	if(check == false){
    	cout << -1 << endl;
    }else{
    	cout << counter << endl;
    }
}