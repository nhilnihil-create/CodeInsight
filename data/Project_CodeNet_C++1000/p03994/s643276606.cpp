#include <iostream>
#include <string>
#define llint long long

using namespace std;

string s;
llint k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> k;
	for(int i = 0; i < (llint)s.size()-1; i++){
		if(s[i] == 'a') continue;
		llint c = s[i]-'a';
		if(26-c<=k){
			k -= 26-c;
			s[i] = 'a';
		}
	}
	k %= 26;
	llint c = s[(int)s.size()-1] - 'a';
	s[(int)s.size()-1] = (c+k) % 26 + 'a';
	
	cout << s << endl;
	
	return 0;
}