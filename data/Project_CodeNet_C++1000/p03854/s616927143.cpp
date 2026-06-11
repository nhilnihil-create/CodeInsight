#include <iostream>
#include <string>

using namespace std;

int main(){
	string S;
	cin >> S;

	while(!S.empty()){
		switch(S[0]){
		case 'e':
			if(S.find("erase") != 0){
				goto NG;
			}

			if(S[5] == 'r'){
				S.erase(0, 6);
			} else {
				S.erase(0, 5);
			}

			break;
		case 'd':
			if(S.find("dream") != 0){
				goto NG;
			}

			if(S.find("dreamer") == 0){
				if(S.find("dreamerase") == 0){
					S.erase(0, 5);
				} else {
					S.erase(0, 7);
				}
			} else {
				S.erase(0, 5);
			}
			break;
		default:
			goto NG;
		}
	}

	cout << "YES" << endl;
	return 0;
NG:
	cout << "NO" << endl;
	return 0;
}
