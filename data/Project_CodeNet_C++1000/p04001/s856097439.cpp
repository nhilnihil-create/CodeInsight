#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();

    int64_t result = 0;

    for (int plus = 0; plus < (1 << (N - 1)); plus++) {
        //cout << "case : plus = " << plus << endl;
        vector<int> s_divided(0);
        int prev_i = -1;

        for (int i = 0; i < N; i++) {
            if (plus & (1 << i)) {
                string temp = s.substr(prev_i + 1, i - prev_i);
                prev_i = i;
                s_divided.push_back(stoi(temp));
            }
        }
        
        if (N == 10 && plus == 0) {
            const char *strnum = s.c_str();
            long num = strtol(strnum, NULL, 10); 
            //cout << "   added " << num << " to result" << endl;
            result += num;
        } else {
            string last_num = s.substr(prev_i + 1, N - prev_i - 1);
            s_divided.push_back(stoi(last_num));
        }

        for (int s_nums : s_divided) {
            //cout << "   added " << s_nums << " to result" << endl;
            result += s_nums;
        }
    }

    cout << result << endl;

    return 0;
}