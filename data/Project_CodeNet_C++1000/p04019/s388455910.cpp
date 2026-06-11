#include <bits/stdc++.h>
using namespace std;

int main() {
	char str[1001];
	scanf("%s", str);
	int n, s, w, e;
	n = 0;
	s = 0;
	w = 0;
	e = 0;
	for(int i = 0; i < (int)strlen(str); i++) {
		if(str[i] == 'N') {
			n++;
		}else if(str[i] == 'S') {
			s++;
		}else if(str[i] == 'W') {
			w++;
		}else if(str[i] == 'E') {
			e++;
		}
	}
	bool ans = true;
	if(n > 0 && s == 0) {
		ans = false;
	}else if(s > 0 && n == 0) {
		ans = false;
	}else if(w > 0 && e == 0) {
		ans = false;
	}else if(e > 0 && w == 0) {
		ans = false;
	}
	if(ans) {
		printf("%s\n", "Yes");
	}else {
		printf("%s\n", "No");
	}
}