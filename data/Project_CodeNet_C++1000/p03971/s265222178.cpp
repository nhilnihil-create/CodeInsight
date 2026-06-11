#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int cur_a = 0, cur_b = 0;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(c == 'a') {
            cur_a++;
        }
        else if(c == 'b') {
            cur_b++;
        }
        if(c == 'a') {
            int sum = cur_a + cur_b;
            if(sum <= a + b) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
        else if(c == 'b') {
            int sum = cur_a + cur_b;
            if(sum <= a + b && cur_b <= b) {
                puts("Yes");
            } else {
                puts("No");
                cur_b--;
            }
        }
        else if(c == 'c') {
            puts("No");
        }
    }
    return 0;
}