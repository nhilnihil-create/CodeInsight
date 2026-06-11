#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int>L(N);
    vector<int>R(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> L.at(i);
        cin >> R.at(i);
        sum += R[i] - L[i] + 1;
    }
    cout << sum << endl;
}