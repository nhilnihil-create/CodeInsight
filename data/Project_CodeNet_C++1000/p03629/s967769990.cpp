#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#define FULL ((1 << 26) - 1)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
    reverse(s.begin(), s.end());

	int arr[10000] = {FULL};
	char mem[10000][26];
    memset(mem, -1, sizeof(mem));
	int exist[26] = {};

	for (int i = 0; i < s.size(); ++i) {
		int& t = exist[s[i] - 'a'];
		if (arr[t] == FULL) {
			t++;
			for (int j = 0; j < 26; ++j) {
				if (!(arr[t] & (1 << j))) {
					mem[t + 1][s[i] - 'a'] = j;
					break;
				}
			}
            arr[t] |= (1 << (s[i] - 'a'));
		}
		else {
			for (int j = 0; j < 26; ++j) {
				if (!(arr[t] & (1 << j))) {
					mem[t + 1][s[i] - 'a'] = j;
					break;
				}
			}
		}
	}

	int len = 0;
	while (arr[len] == FULL) {
		len++;
	}

	string ans;
	int start;
	for (int i = 0; i < 26; ++i) {
		if (!(arr[len] & (1 << i))) {
			start = i;
			ans.push_back(start + 'a');
			break;
		}
	}

	while (len > 1) {
        if (mem[len][start] == -1) {
            ans.push_back('a');
		    start = 0;
        }
        else {
            ans.push_back(mem[len][start] + 'a');
		    start = mem[len][start];
        }
		len--;
	}

	cout << ans;
}