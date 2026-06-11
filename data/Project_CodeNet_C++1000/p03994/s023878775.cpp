#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	rep(i, s.size()) {
        if(s[i]=='a') continue;
		if ('z' - s[i] + 1 <= k) {
			k -= 'z' - s[i] + 1;
			s[i] = 'a';
		}
	}
	if (k > 0)  s.back() = 'a'+(s.back()-'a' + k) % 26;
	cout << s << endl;
}
