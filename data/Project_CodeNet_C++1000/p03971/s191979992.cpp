#include <bits/stdc++.h>
using namespace std;

void check(string s, int n, int a, int b){
    int passed = 0, rank = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'a'){
            if (passed < a + b){
                cout << "Yes" << endl;
                passed++;
            } else{
                cout << "No" << endl;
            }
        } else if (s[i] == 'b'){
            if (passed < a + b && rank + 1 <= b){
                cout << "Yes" <<  endl;
                passed++;
                rank++;
            } else {
                cout << "No" << endl;
            }
        } else{
            cout << "No" << endl;
        }
    }
}

int main(void){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    check(s, n, a, b);
    return 0;
}