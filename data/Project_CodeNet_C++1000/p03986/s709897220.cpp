#include<iostream>
using namespace std;

string str;
int main() {
    int s = 0, t = 0;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == 'S') s++;
        else s > 0 ? s-- : t++;
    }
    cout << t + s << endl;
    return 0;
}
