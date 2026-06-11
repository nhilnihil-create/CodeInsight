#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int a_now = 0;
    int b_now = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            if(a_now + b_now < a + b){
                a_now++;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i] == 'b'){
            if(a_now + b_now < a + b && b_now < b){
                cout << "Yes" << endl;
                b_now++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    } 
}