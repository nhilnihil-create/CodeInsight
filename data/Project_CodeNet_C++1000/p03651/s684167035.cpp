#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int lcd(int p, int q) {
    int upper, lower, r;

    if (p >= q) upper = p, lower = q;
    else upper = q, lower = p;
    r = upper % lower;
    if (r)return lcd(lower, r);
    else return lower;
}

int main() {
    int N, K;
    cin >> N >> K;

    int mx = -1;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (N == 1) {
        if (K == a[0] || K == 0)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }

    else {
        int lcn = lcd(a[0], a[1]);
        for (int i = 2; i < N; i++) 
            lcn = lcd(lcn, a[i]);
        
        if (K % lcn == 0 && K <= mx)
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;

    }
    
}
