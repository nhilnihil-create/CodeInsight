#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    vector<int> rate(8,0);
    int r, over3200 = 0;
    for (int i = 0; i < n; i++) {
        cin >> r;
        if(r>=3200) {over3200++;continue;}
        rate[(int)(r/400)]++;
    }
    int ret_min = 0;
    for (int i = 0; i < 8; i++) ret_min += (rate[i]>0) ? 1 : 0;
    if (ret_min==0) {ret_min = 1; over3200--;} // Ohh, I totally forgot.. All person are crazy in AtCoder, in this case.(in1.txt)

    int ret_max = ret_min + over3200; // ??? min(ret_min+over3200, 8); -> See https://atcoder.jp/contests/abc064/clarifications

    cout << ret_min << " " << ret_max << endl;
    return 0;
}