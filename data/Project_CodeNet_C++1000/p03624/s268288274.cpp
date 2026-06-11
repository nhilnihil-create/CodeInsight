#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int i;
	bool ok = false;
	int arr[26] = {0};
	for(i=0; i<s.length(); i++){
		arr[s[i]-'a']++;
	}
	for(i=0; i<26; i++){
		if(arr[i]==0){
			ok = true;
			break;
		}
	}
	if(ok){
		//cout << 'a'+i << endl;
		printf("%c\n", 'a'+i);
	}
	else{
		cout << "None\n";
	}
	return 0;
}
