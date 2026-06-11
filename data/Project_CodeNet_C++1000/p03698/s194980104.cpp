#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    string s;
    vector<int> arr(26, 0);
    cin >> s;
    for(char c: s)
        arr[c-'a'] = 1;
    if (accumulate(arr.begin(), arr.end(), 0) == s.size())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
