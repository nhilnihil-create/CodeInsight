#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(void){
    int h, w, ans1, ans2;
    string s;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 'A'; j < 'A' + w; j++) {
            cin >> s;
            if (s == "snuke") {
                ans1 = i + 1;
                ans2 = j;
            }
        }
    }
    cout << char(ans2) << ans1;
    return 0;
}
