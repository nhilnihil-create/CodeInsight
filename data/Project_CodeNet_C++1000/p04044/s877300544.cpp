#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s.at(i);
    }
    sort(s.begin(),s.end());
    for(int i=1; i<n; i++){
        s.at(0)+=s.at(i);
    }
    cout << s.at(0) << endl;
}