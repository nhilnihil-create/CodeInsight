#include <iostream>
using namespace std;

int main() {
	string ss;
	cin >> ss;
	int arr[26]={};
	for (int i=0; i<ss.length(); i++){
		arr[(ss[i]-'a')]++;
	}
	for (int i=0; i<26; i++){
		if (arr[i]>1){
			cout << "no\n";
			return 0;
		}
	}
	cout << "yes\n";
}