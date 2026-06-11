#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int n = s.length();
    int cou = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cou == 0){
            if(s[i] == 'S'){
                cou++;
            }
        }else{
            if(s[i] == 'S'){
                cou++;
            }else{
                ans += 2;
                cou--;
            }
        }
    }

    cout << n - ans << endl;
}