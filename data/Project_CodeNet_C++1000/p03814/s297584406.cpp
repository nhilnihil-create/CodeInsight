#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    int A_posi = 0;
    int Z_posi = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A'){
            A_posi = i;
            break;
        }
    }
    for(int i = S.size() - 1; i >= 0; i--){
        if(S[i] == 'Z'){
            Z_posi = i;
            break;
        }
    }
    
    int ans = Z_posi - A_posi + 1;
    cout << ans << endl;
    

}
