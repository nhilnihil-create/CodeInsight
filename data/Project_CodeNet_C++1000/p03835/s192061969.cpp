#include <iostream>
using namespace std;

int main(){
  	int K, S;
  	cin >> K >> S;
  	int counter=0;
  	for(int A=0;A<=K;A++){
	  	for(int B=0;B<=K;B++){
	        if(S-A-B >=0 && S-A-B <= K) counter++;
    	}
    }
  	cout << counter << endl;
}