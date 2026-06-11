#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n * 3);
    for (int i = 0; i < n * 3; i++) {
        cin >> a.at(i);
    }

    map<int, int> left_map;
    long long left_sum = 0;
    for (int i = 0; i < n; i++) {
        left_sum += a.at(i);
        left_map[a.at(i)]++;
    }

    vector<pair<int, int>> sorted_right(n * 2);
    for (int i = 0; i < n * 2; i++) {
        sorted_right.at(i) = make_pair(a.at(n + i), n + i);
    }
    sort(sorted_right.begin(), sorted_right.end());

    vector<bool> used(n * 3, false);
    long long right_sum = 0;
    for (int i = 0; i < n; i++) {
        right_sum += sorted_right.at(i).first;
        used.at(sorted_right.at(i).second) = true;
    }
    int right_max_index = n;
    
    vector<bool> done(n * 3);
    long long ans = left_sum - right_sum;
    for (int i = n; i < n * 2; i++) {
        done.at(i) = true;
        if (used.at(i)) {
            right_sum -= a.at(i);
            
            while (done.at(sorted_right.at(right_max_index).second)) right_max_index++;
            
            right_sum += sorted_right.at(right_max_index).first;
            done.at(sorted_right.at(right_max_index).second) = true; 
            used.at(sorted_right.at(right_max_index).second) = true;
            right_max_index++;
        }

        auto ite = left_map.begin();
        if (ite -> first < a.at(i)) {
            left_sum -= ite -> first;
            left_sum += a.at(i);

            left_map[ite -> first]--;
            if (ite -> second == 0) left_map.erase(ite -> first); 
            left_map[a.at(i)]++;
        }

        ans = max(ans, left_sum - right_sum);
    }
    
    cout << ans << endl;
}   