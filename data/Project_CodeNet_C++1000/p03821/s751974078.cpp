#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long cnt = 0;
    long long tmpCnt;
    cin >> num;

    vector<long long> vec(num);
    vector<long long> baisu(num);

    for (long long i = 0; i < num; i++) cin >> vec.at(i) >> baisu.at(i);

    for (long long i = num-1; i >= 0; i--) {
        //
        tmpCnt = baisu.at(i) - ((vec.at(i) + cnt) % baisu.at(i));
        if(tmpCnt < baisu.at(i)) cnt += tmpCnt;
    }

    cout << cnt;
    //
}