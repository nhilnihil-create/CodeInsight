#include <bits/stdc++.h>
using namespace std;


int main() {
    string num;
    long long count = 0;

    cin >> num;
    int n = num.size()-1;
    for (int bit = 0; bit < (1<<n); bit++) {
        vector<int> S;
        long long tmp = num[0]-'0';
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                count+=tmp;
                tmp=num[i+1]-'0';
            } else{
                tmp = tmp*10;
                tmp+= num[i+1]-'0';
            }
        }
        count+=tmp;
    }
    cout << count << endl;

    
}

