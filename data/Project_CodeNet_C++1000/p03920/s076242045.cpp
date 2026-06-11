#include "bits/stdc++.h"
using namespace std;

int main() {
        int n;
        cin >> n;
        int sum = 0;
        int i = 1;
        while (sum < n) {
                sum += i;
                i ++;
        }
        int limit = i - 1;
        int ex = sum - n;
        for (int i = 1; i <= limit; i ++) {
                if (i != ex) cout << i << endl;
        }
        return 0;
}

