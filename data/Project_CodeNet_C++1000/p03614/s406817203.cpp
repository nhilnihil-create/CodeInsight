#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    bool flag = false;
    int cnt = 0;
    for (int i = 1; i < N + 1; i++) {
        int a;
        cin >> a;
        if (a == i) {
            if (flag) {
                flag = false;
            } else {
                ++cnt;
                flag = true;
            }
        } else {
            flag = false;
        }
    }
  cout << cnt << endl;
}