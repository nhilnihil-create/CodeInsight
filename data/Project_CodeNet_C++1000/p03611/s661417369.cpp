#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> table(1e5+10,0);
    for (long long i=0; i<N; i++) {
        long long a;
        cin >> a;
        a+=1;
        table.at(a-1)++;
        table.at(a)++;
        table.at(a+1)++;
    }
    sort(table.begin(), table.end());
    reverse(table.begin(), table.end());
    cout << table.at(0);
}