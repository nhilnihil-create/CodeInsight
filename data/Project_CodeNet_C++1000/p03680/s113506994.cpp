#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin >> n;

vector<int> a(n + 1);
vector<int> past(n + 1);

for (int i = 1; i <= n; i++) cin >> a.at(i);

int count = 0;
int current = 1;
past.at(1) = 1;
int answer = -1;

for (int i = 1; i <= n; i++) {
    current = a.at(current);
    count++;
    if (past.at(current) == 1) {
        break;        
    } else {
        past.at(current) = 1;
        if (current == 2) {
            answer = count;
            break;
        }
    }
}

cout << answer << endl;

return 0;
}