#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(){
	string S;
	cin >> S;
	
	for(ll i = 1; i < S.size(); i++){
		if(S[i]==S[i-1]){
				cout << i << " " << i + 1 << endl;
				return 0;	
			}
		}
		
	for(ll i = 2; i < S.size(); i++){
		if(S[i]==S[i-2]){
			cout << i - 1 << " " << i + 1 << endl;
			return 0;		
			}
		}
		
	cout << -1 << " "<< -1 << endl;
	
	return 0;
	}
