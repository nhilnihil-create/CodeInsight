#include <iostream>
using namespace std;
string s;
int main(){
    cin >> s;
    int ans = s.size();
    int s_num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
                s_num++;
        }
        if (s[i] == 'T') {
            if (s_num > 0) {
                s_num--;
                ans -= 2;
            }
        }
    }
    cout << ans << endl;
}
