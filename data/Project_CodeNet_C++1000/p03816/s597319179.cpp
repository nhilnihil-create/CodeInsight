#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    map<int,int> mp;
    while(N--) {
        int A;
        cin >> A;
        mp[A]++;
    }

    int k = mp.size();
    if(k%2) {
        cout << k << endl;
    } else {
        cout << k-1 << endl;
    }
    return 0;
}
