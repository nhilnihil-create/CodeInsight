#include <bits/stdc++.h>
using namespace std;
int n,l;
vector <string> s;
int main(){
    cin >> n >> l;
    s = vector<string>(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    for(int i = 0; i < n; i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}