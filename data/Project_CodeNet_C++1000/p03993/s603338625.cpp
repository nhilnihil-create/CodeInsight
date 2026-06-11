#include <iostream>
#include <map>
using namespace std;

int main(void) {
    int N;cin>>N;
    map<int, int> mp;
    int result = 0;
    for (int i = 1; i <= N; i++) {
        int a;cin>>a;
        if (mp.find(a) != mp.end()) {
            if (mp[a] == i) result++;
        }
        mp[i] = a;
    }
    cout << result << endl;
    return 0;
}