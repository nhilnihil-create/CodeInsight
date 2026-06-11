#include <iostream>

std::string s1, s2, s3;
int i, j, k, cur;

void solve() {
    std::cin >> s1 >> s2 >> s3;
	cur = 0;
	i = 0;
    j = 0;
    k = 0;
	while (true) {
		if (cur == 0) {
            while (s1[i] == 'a')
                    i++;
            if (i == s1.length()) {
                std::cout << 'A' << std::endl;
                return;
            }
            else {
                if (s1[i] == 'c')
                    cur = 2;
                else 
                    cur = 1;
            }
            ++i;
		} else if (cur == 1) {
            while (s2[j] == 'b')
                j++;
            if (j == s2.length()) {
                std::cout << 'B' << std::endl;
                return;
            }
            else {
                if (s2[j] == 'c')
                    cur = 2;
                else
                    cur = 0;
            }
            ++j;
		} else {
            while (s3[k] == 'c') 
                k++;
            if (k == s3.length()) {
                std::cout << 'C' << std::endl;
                return;
            }
            else {
                if (s3[k] == 'a')
                    cur = 0;
                else
                    cur = 1;
            }
            ++k;
		}
	}
}

int main() {
	solve();
    return 0;
} 
