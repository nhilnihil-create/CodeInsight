#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int cnt_g = 0;
    int cnt_p = 0;
    int point = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'p') {
            if(cnt_p == cnt_g) {
                cnt_g++;
                point--;
            } else {
                cnt_p++;
            }
        } else {
            if(cnt_p == cnt_g) {
                cnt_g++;
            } else {
                cnt_p++;
                point++;
            }
        }
    }

    cout << point << endl;
    return 0;
}
