#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    int N, x;
    bool incremental;
    int first = 0;
    int ans = 1;
    int prev;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (i != 0) {
            if (prev > x) {
                if (first == 0) {
                    incremental = false;
                    first++;
                }
                if (incremental) {
                    incremental = false;
                    first = 0;
                    ans++; 
                }
            } else if (prev < x){
                if (first == 0) {
                    incremental = true;
                    first++;
                }
                if (!incremental) {
                    incremental = true;
                    first = 0;
                    ans++;
                }
            } 
        }
        prev = x;
        A.push_back(x);
    }
    cout << ans << endl;
}
