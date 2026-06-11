#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s;
	int i;
	cin >> s;
	bool can[26];
	
	for(i=0; i<26; i++)
		can[i] = false;	
	
	for(i=0; i<s.length(); i++){
		for(char c='a'; c<='z'; c++){
			if(s[i] == c){
				can[s[i] - 'a'] = true;
				break;
			}
		}
	}

	for(i=0; i<26; i++)
		if(!can[i]){
			cout << (char)(i + 'a') << endl;
			return 0;
		}
		cout << "None" << endl;
}
