#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }
    sort(vec.begin(), vec.end());
    vector<int> num(100000,0);
    for(int i = 0; i < N; i++){
        num.at(vec.at(i))++;
    }

    int ma = 0;
    for(int i = 2; i < 100000; i++){
        ma = max(num.at(i-2) + num.at(i-1) + num.at(i), ma);
    }
    cout << ma << endl;
}