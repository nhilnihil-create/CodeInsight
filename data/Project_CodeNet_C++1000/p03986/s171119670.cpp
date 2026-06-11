//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    string X;
    cin >> X;

    int N = X.size();
    vector<int> s, t;
    for (int i = 0; i < N; i++) {
        if (X[i] == 'S') s.push_back(i);
        else t.push_back(i);
    }
    
    int left = 0;
    bool flag = false;
    int ans = N;
    for (int i = 0; i < N / 2&&!flag; i++) {
        for (int j = left; j < N / 2; j++) {
            if (s[i] < t[j]) {
                ans -= 2;
                left = j + 1;
                break;
            }
            else if (j == N / 2 - 1) {
                flag = true;
                break;
            }
        }
    }

    cout << ans << endl;
    
}
