
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin >> s;
    rep(i,s.size()/2){
        cout << s.at(2*i);
    }
    if(s.size()%2 == 1){
        cout << s.at(s.size()-1);
    }
    cout << endl;
    
}