#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    map<string, int>d;
    for (int i=0; i<N; i++) {
        int n;
        cin >> n;
        if (n < 400) {
            d["hai"] = 1;
        } else if (n < 800) {
            d["cha"] = 1;
        } else if (n < 1200) {
            d["midori"] = 1;
        } else if (n < 1600) {
            d["mizu"] = 1;
        } else if (n < 2000) {
            d["ao"] = 1;
        } else if (n < 2400) {
            d["ki"] = 1;
        } else if (n < 2800) {
            d["daidai"] = 1;
        } else if (n < 3200) {
            d["aka"] = 1;
        } else {
            if (d.count("ziyu") > 0) {
                d["ziyu"] = d["ziyu"] + 1;
            } else {
                d["ziyu"] = 1;
            }
        }
    }

    int64_t min_count = 0;
    int64_t max_count = 0;
    bool min_used = false;
    for (auto a : d) {
        if (a.first == "ziyu") {
            if (d.size() == 1 && !min_used) {
                min_count += 1;
                min_used = true;
            }
            max_count += a.second;
        } else {
            min_count += 1;
            max_count += 1;
        }
    }

    cout << min_count << " " << max_count << endl;
    return 0;
}