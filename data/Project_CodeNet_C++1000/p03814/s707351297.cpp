#include<iostream>
#include<string>
#include<algorithm>
#define rep(i, n) for(i=0; i<n; i++)
using namespace std;
int main() {
    string s;
    cin >> s;
    int i, len = s.length();
    int count = 0, temp = 0;
    bool ok = false;
    rep(i, len){
        if(s[i]=='A'){
            temp = i;
            break;
        }
    }
    for(i=len-1; i>=0; i--){
        if(s[i]=='Z'){
            count = i;
            break;
        }
    }
    cout << count-temp+1 << endl;
    return 0;
}