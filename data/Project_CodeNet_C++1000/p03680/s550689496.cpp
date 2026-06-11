#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int>A;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        a--;
        A.push_back(a);
    }
    
    int ans = 0;
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        if (ans == 1) {
            cout << sum << endl;
            return 0;
        }
        if (sum >= N) {
            cout << -1 << endl;
            return 0;
        }
        sum++;
        ans = A[ans];
    }
}