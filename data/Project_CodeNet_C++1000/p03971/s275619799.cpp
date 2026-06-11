#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,a,b;
    string s;
    cin >> n >> a >> b >> s;
    int x = a + b;
    int y = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            if(x){
                cout << "Yes" << endl;
                x--;
            }else{
                cout << "No" << endl;
            }
        }else if (s[i] == 'b'){
            if(x && y < b){
                cout << "Yes" << endl;
                x--;
                y++;
            }else{
                cout << "No" << endl;
            }
        }else if (s[i] == 'c'){
            cout << "No" << endl;
        }
    }
    return 0;
}