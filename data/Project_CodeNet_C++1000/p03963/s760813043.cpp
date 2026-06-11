#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int count = N;
    int answer = K;
    for (int i = 1; i < count; i++)
    {
        answer *= (K-1);
    }
    cout << answer << endl;
    



}
