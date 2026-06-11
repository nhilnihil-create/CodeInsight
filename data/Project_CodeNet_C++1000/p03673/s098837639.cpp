#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    bool rev = false;
    vector<int> b, c;
    for(int i = 0; i < n; i++){
        if(rev){
            c.push_back(a[i]);
        }else{
            b.push_back(a[i]);
        }
        rev ^= true;
    }
    if(rev){
        for(int i = b.size() - 1; i >= 0; i--){
            cout << b[i] << " ";
        }
        for(int i = 0; i < c.size(); i++){
            cout << c[i] << " ";
        }
    }else{
        for(int i = c.size() - 1; i >= 0; i--){
            cout << c[i] << " ";
        }
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
    }
    cout << endl;
    return 0;
}