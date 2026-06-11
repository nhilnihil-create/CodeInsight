#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> s;
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end());
    for(auto x : s)
        cout << x;
    return 0;
}
