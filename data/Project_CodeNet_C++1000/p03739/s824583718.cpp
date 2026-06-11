#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans1 = 0, ans2 = 0;  
    long long total;
    for (int p = 0; p < 2; p++) {
        ans2 = ans1;
        ans1 = 0;
        long long temp;
        if (p == 0) {
            if (a[0] == 0) {
                total = 1;
                ans1++;
            }
            else {
                total = a[0];
            }

        }

        if (p == 1) {
            if (a[0] == 0) {
                total = -1;
                ans1++;
            }
            else {
                if (a[0] > 0) {
                    total = -1;
                    ans1 = a[0] + 1;
                }
                else {
                    total = 1;
                    ans1 = -a[0] + 1;
                }
            }

        }

        for (int i = 1; i < n; i++) {
            //cout << "total=" << total << endl;
            temp = a[i];
            if (total > 0) {
                if (total + a[i] >= 0) {
                    a[i] = -(total + 1);
                }
                total += a[i];
                ans1 += abs(a[i] - temp);
                a[i] = temp;
            }
            else if (total < 0) {
                if (total + a[i] <= 0) {
                    a[i] = (-total + 1);
                }
                total += a[i];
                ans1 += abs(a[i] - temp);
                a[i] = temp;
            }
        }
        //cout << ans1 << "  " << ans2 << endl;
    }
    
    cout << min(ans1,ans2) << endl;
}
