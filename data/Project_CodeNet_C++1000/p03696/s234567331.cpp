#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    deque<char> A;
    rep(i, s.size()) {
        if (!A.empty() && A.back() == '(' && s[i] == ')')
            A.pop_back();
        else
            A.push_back(s[i]);
    }

    string left = "", right = "";
    while (!A.empty() && A.front() == ')') {
        left += '(';
        A.pop_front();
    }

    while (!A.empty() && A.back() == '(') {
        right += ')';
        A.pop_back();
    }

    string res = left + s + right;
    cout << res << endl;
}