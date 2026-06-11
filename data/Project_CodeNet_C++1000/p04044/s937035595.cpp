#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l;
    cin >> n >> l;
    vector <string> s;
    while(n--){
        string a;
        cin >> a;
        s.push_back(a);
    }
    sort(s.begin(), s.end());
    for(auto it : s) cout << it;
    return 0;
}
