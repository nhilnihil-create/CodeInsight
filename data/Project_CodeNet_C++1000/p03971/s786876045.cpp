#include <bits/stdc++.h>

using namespace std;

long long cost(vector<int> X, int p) {
    long long ans = 0;
    for (auto x : X) {
        ans += (x - p) * (x - p);
    }
    return ans;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int C = 0;
    int F = 0;
    auto ok1 = [&]() {
        return C < A + B;
    };
    auto ok2 = [&]() {
        return ok1() && F < B;
    };
    auto chk_inc = [&](char c) {
        if (c == 'a') {
            bool f = ok1();
            if (f)C++;
            return f;
        } else if( c == 'b'){
            bool f = ok2();
            if (f)C++, F++;
            return f;
        }else{
            return false;
        }
    };
    for(int i = 0 ; i < N ; i++){
        char c;
        cin >> c;
        cout << (chk_inc(c) ? "Yes" : "No") << endl;
    }
}