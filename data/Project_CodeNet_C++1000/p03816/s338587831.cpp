#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    map<int,int> mp;
    for(int i=0; i<N; i++) {
        int A;
        cin >> A;
        mp[A]++;
    }

    int d = 0;
    for(auto itr=mp.begin(); itr!=mp.end(); itr++) {
        d += itr->second - 1;
    }

    cout << N - ((d+1)/2) * 2 << endl;
    return 0;
}
