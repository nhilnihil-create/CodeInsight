#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int N, L; cin >> N >> L;
    vector<string> vector;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        vector.push_back(S);
    }
    sort(vector.begin(), vector.end());
    for (int i = 0; i < N; i++) {
        cout << vector[i];
    }
    cout << endl;
}
