#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int main(void) {
    string s; cin >> s;

    int flag;
    for (int i = int(s.length()) - 2; i > 0; i--) {
        flag = 1;
        if (i % 2 == 0)
            continue;
        int front  = i / 2;
        int end = i;
        while (front >= 0) {
            if (s[front] != s[end]) {
                flag = 0;
                break;
            }
            front--;
            end--;
        }
        if (flag == 0)
            continue;
        cout << i + 1 << endl;
        break;
    }
    
    return 0;
}