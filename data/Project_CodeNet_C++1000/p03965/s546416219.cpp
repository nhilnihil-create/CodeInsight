#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long ull;


int main(int argc, char const *argv[]) {
    string s;
    cin >> s;
    int N = s.length();
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { // g
            if (s[i] == 'p') {
                result -= 1;
            }
        } else {
            if (s[i] == 'g') {
                result += 1;
            }
        }
    }
    cout << result << endl;

    return 0;
}
