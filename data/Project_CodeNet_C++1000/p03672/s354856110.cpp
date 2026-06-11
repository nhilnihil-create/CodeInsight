#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for (int i = s.length()-1; 0 < i; i--){
        if (i%2 == 0){
            vector<string> r(i);
            for (int j = 0; j < i; j++){
                r[j] = s[j];
            }
            bool flag = true;
            for (int k = 0;k < i/2;k++){
                if (r[k] != r[k+(i/2)]){flag = false;}
            }
            if (flag == true){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}