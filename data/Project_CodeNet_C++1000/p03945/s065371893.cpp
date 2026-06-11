#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size()-1; i++){
        if((s[i] == 'B' && s[i+1] == 'W' )||(s[i] == 'W' && s[i+1] == 'B')){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}