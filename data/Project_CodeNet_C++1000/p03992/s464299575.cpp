#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;

    int N = s.length();

    for (int i = 0; i <= N; i++){
        if (i == 4){
            cout << ' ';
        }
        else if (i < 4){
            cout << s[i];
        }
        else if (i > 4){
            cout << s[i - 1];
        }
    }
    cout << endl;
}