#include <bits/stdc++.h>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int len = str.size();
    int t = len;
    
    bool flag;
    while (true) {
        if (len%2 == 0) {
            flag = true;
            for (int i=0; i<len/2; i++) {
                if (str[i] != str[len/2+i]) {
                    flag = false;
                    break;
                }
            }
            if (flag && len != t) {
                cout << len << endl;
                return 0;
            }
        }
        str.erase(len-1);
        len--;
    }
}
