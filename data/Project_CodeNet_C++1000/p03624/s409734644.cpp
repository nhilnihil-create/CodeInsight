#include <iostream>
#include <string>
using namespace std;
int main(){
	char str[110000];
	cin>>str;
	int num[26] = {0};
	int length=0;
	int a = 0;
	while (str[a] != '\0') {
		length++;
		a++;
	}
	bool flag = false;
	for (int i = 0;i <length ;i++) 
		num[str[i] - 'a']++;
	for (int k = 0;k < 26;k++) {
		if (num[k] == 0) {
			cout << (char)(k + 'a');
			flag = true;
			break;
		}
	}
	if (!flag) cout << "None";

}