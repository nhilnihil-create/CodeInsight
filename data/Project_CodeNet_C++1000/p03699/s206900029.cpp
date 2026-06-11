#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> score(N),not_ten;

    int total_s = 0;

    for(int i=0; i<N; i++) {
        cin >> score[i];
        total_s += score[i];
        if(score[i] % 10 != 0) not_ten.push_back(score[i]);
    }

    if(total_s % 10 == 0 && not_ten.size() > 0){
        sort(not_ten.begin(), not_ten.end());
        total_s -= not_ten[0];
    }

    if (total_s % 10 == 0) total_s = 0;

    cout << total_s << endl;
}