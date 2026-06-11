#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

using ll = long long;

int main() {
    int n, a;
    cin >> n;
    vector<int> input(n*3);
    for (int i=0; i<n*3; ++i) {
        cin >> a;
        input[i] = a;
    }
    sort(input.begin(), input.end());
    ll sum = 0;
    for (int i=n; i<n*3; i+=2) {
        sum += input[i];
    }
    cout << sum << endl;
}
