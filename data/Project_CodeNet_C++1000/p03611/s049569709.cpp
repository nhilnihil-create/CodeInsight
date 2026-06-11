#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);
    int preX = 0;
    int X = 0;
    int postX = 0;
    int count_max = 0;
    sort(a.begin(),a.end());
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (a.at(i) == j) postX++;
        else if (a.at(i) > j) {
            if (preX + X + postX > count_max) count_max = preX + X + postX;
            preX = X;
            X = postX;
            postX = 0;
            i--;
            j++;
        }
        if (i == N - 1 && preX + X + postX > count_max) count_max = preX + X + postX;
    }
    cout << count_max << endl;
}
