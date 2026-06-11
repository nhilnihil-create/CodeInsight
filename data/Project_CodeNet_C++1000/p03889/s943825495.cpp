#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;

    int l = s.size();
    if(l%2 != 0){
        cout << "No" << endl;
        return 0;
    }
    int num[l] = {};
    for(int i=0;i<l;i++){
        if(s[i] == 'b'){
            num[i] = 1;
        }else if(s[i] == 'd'){
            num[i] = -1;
        }else if(s[i] == 'p'){
            num[i] = 2;
        }else{
            num[i] = -2;
        }
    }

    for(int i=0;i<l/2;i++){
        if(num[i] + num[l-1-i] != 0){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}