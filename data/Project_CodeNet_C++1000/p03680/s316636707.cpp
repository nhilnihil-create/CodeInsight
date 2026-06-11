#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v;
    for(int i = 0; i < N; i++) {
        int z;
        cin >> z;
        z--;
        v.push_back(z);
    }

    int now = 0, c = 0;
    for(;;) {
        if(now == 1) {
            cout << c << endl;
            break;
        }
        if(c >= N) {
            cout << -1 << endl;
            break; 
        }
        c++;
        now = v[now];
    }
}