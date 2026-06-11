#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    cout << s.front() << n-2 << s.back() << endl;
}