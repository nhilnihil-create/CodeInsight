#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    int b, e;
    for(int i = 0; i < n; i++){
        if(s[i]=='A') {   
            b = i;
            break;
        }
    }

    for(int j = 0; j < n; j++){
        if(s[j] == 'Z') {
            e = j;
        }
    }

    cout  << e - b + 1 << endl;
    return 0;
}