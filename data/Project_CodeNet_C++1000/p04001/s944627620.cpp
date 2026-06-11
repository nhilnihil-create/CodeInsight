#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> possibles;
    for (int bit = 0; bit < (1 << n - 1); bit++) {
        string possible = "";
        for (int i = 1; i < n; i++) {
            possible += s.at(i - 1);
            if (bit & 1 << i - 1) possible += "+"; 
        }
        possible += s.at(n - 1);
        possibles.push_back(possible);
    }
    long long total = 0;
    for (int i = 0; i < possibles.size(); i++) {
        string tmp = "";
        for (int j = 0; j < possibles.at(i).size(); j++) {
            if (possibles.at(i).at(j) == '+') {
                total += stoi(tmp);
                tmp = "";
            } else {
                tmp += possibles.at(i).at(j);
                if (j == possibles.at(i).size() - 1) total += stoll(tmp);
            }
        }
    }
    cout << total << endl;


    return 0;
}