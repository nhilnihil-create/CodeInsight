#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
    int n,a,b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    int countpass = 0;
    int countb = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'c'){
            cout << "No" << endl;
        } else {
            if(s[i] == 'a' && countpass < a+b){
                cout << "Yes" << endl;
                countpass++;
            } else if(s[i] == 'b' && countpass < a+b && countb < b){
                cout << "Yes" << endl;
                countb++;
                countpass++;
            } else {
                cout << "No" << endl;
            }
        }
    }
}