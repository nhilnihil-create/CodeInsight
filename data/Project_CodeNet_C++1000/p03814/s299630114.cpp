#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int count = 0;

    for(int i = 0; i < S.size(); i++){
        if(S.at(i) == 'A'){
            for(int j = S.size()-1; j > i; j--){
                if(S.at(j) == 'Z'){
                    cout << j - i + 1 << endl;
                    return 0;
                }
            } 
        }
    }
}