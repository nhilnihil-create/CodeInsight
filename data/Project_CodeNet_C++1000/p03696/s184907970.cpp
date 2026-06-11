#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int INF = 1e9;
const ll MOD = 1e9 + 7;  

int main(){
    int N;
    string s;
    cin >> N >> s;
    string check = string();
    for(int i = 0 ; i < N; i++) check += '0';
    int i = 0;
    for(int k = 0; k < N; k++){
        if(check[i] == '1') {
            i++;
            continue;
        }
        if(s[i] == '('){
            bool flag = true;
            for(int j = i+1; j < s.length(); j++){
                if(s[j] == ')' && check[j] == '0'){
                    check[j] = '1';
                    check[i] = '1';
                    flag = false;
                    break;
                }
            }
            if(flag){
                check[i] = '1';
                check += '1';
                s += ')';
            }
        }
        else if(s[i] == ')'){
            bool flag = true;
            for(int j = i-1; j >= 0; j--){
                if(s[j] == '(' && check[j] == '0'){
                    check[j] = '1';
                    check[i] = '1';
                    flag = false;
                    break;
                }
            }
            if(flag){
                check[i] = '1';
                check = '1' + check;
                s = '(' + s;
                i++;
            }
        }
        i++;
    }
    cout << s << endl;
    return 0;
}

