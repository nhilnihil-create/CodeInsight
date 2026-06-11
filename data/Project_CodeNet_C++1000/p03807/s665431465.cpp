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
    int N;
    cin >> N;

    int a;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a % 2)cnt++;
    }
    if (cnt % 2)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
