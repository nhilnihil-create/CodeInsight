#include <iostream>
#include <strstream>
#include <string>
#include <deque>
#include <vector>
#include <map>
typedef unsigned int UINT;
using namespace std;

int main(void) {
    map<string, int > mas;
    int H, W;
    string in;
    cin >> H >> W;
    const int size = H * W;
    for (int index = 0; index < size; index++) {
        cin >> in;
        mas[in] = index;
    }
    int ans_index = mas["snuke"];

    string ans = "A";
    ans[0] = 'A' + ans_index % W;
    ans+= to_string((ans_index /W)+1);
    cout << ans << endl;
    return 0;
}
