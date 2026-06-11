#include <iostream>
#include <string>

using namespace std;

int main(){
	string S;
	cin >> S;

	cout << ((S.size()%2==0 ^ S[0] == S[S.size()-1]) ? "Second" : "First") << endl;
	return 0;
}
