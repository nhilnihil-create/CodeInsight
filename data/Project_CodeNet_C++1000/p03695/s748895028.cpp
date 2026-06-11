#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    map<string, int> rateN;
    rateN.insert(make_pair("grey", 0));
    rateN.insert(make_pair("brown", 0));
    rateN.insert(make_pair("green", 0));
    rateN.insert(make_pair("lightblue", 0));
    rateN.insert(make_pair("blue", 0));
    rateN.insert(make_pair("yellow", 0));
    rateN.insert(make_pair("orange", 0));
    rateN.insert(make_pair("red", 0));
    rateN.insert(make_pair("overred", 0));
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a < 400) {
            ++rateN["grey"];
        }
        else if (a < 800) {
            ++rateN["brown"];
        }
        else if (a < 1200) {
            ++rateN["green"];
        }
        else if (a < 1600) {
            ++rateN["lightblue"];
        }
        else if (a < 2000) {
            ++rateN["blue"];
        }
        else if (a < 2400) {
            ++rateN["yellow"];
        }
        else if (a < 2800) {
            ++rateN["orange"];
        }
        else if (a < 3200) {
            ++rateN["red"];
        }
        else {
            ++rateN["overred"];
        }
    }

    int ansMin = 0;
    for (auto e : rateN) {
        if (e.first != "overred" && e.second > 0) {
            ++ansMin;
        }
    }
    int ansMax = ansMin + rateN["overred"];
    ansMin = max(1, ansMin);
    cout << ansMin << " " << ansMax << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
