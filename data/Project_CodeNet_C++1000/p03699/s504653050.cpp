#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, tmp;
    vector<int> s;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        s.emplace_back(tmp);
    }
    int sum = accumulate(s.begin(), s.end(), 0);
    if (sum % 10 != 0){
        cout << sum << endl;
    } else{
        sort(s.begin(), s.end());
        bool flag = true;
        for (int i=0; i<s.size(); i++){
            if ((sum - s[i]) % 10 != 0){
                sum -= s[i];
                flag = false;
                break;
            }
        }
        cout << (flag ? 0 : sum) << endl;
    }
    return 0;
}