#include<iostream>
#include <algorithm>
#include <string>
#include<math.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    char answ = 0;
    int ansh = 0;
    rep(i, h) {
        rep(j, w) {
            string str;
            cin >> str;
            if (str == "snuke") {
                answ = 'A' + j;
                ansh = i + 1;
            }
        }
    }
    cout << answ << ansh << endl;
    return 0;
}
