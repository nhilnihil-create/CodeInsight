#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string S;
    cin >> S;

    int A_index = -1;
    for(int i=0; i<S.size(); i++){
        if(S[i] == 'A'){
            A_index = i;
            break;
        }
    }

    int Z_index = -1;
    for(int i=S.size()-1; i>=0; i--){
        if(S[i] == 'Z'){
            Z_index = i;
            break;
        }
    }

    cout << Z_index - A_index + 1 << endl;
    return 0;
}