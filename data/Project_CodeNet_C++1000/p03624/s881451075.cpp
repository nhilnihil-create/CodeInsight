#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
    string s;
    cin >> s;
    string a;
    a = "abcdefghijklmnopqrstuvwxyz";
    int num[26] = {0};
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(s[i] == a[j]) ++num[j];
        }
    }
    for(int i = 0; i < 26; i++){
        if(num[i] == 0){
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}