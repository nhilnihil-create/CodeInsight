#include <iostream>
#include <string>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int l = S.length();
    
    int a,z;
    for(int i = 0 ; i < l ; i++){
        if(S[i] == 'A'){
            a = i;
            break;
        }
    }
    for(int i = 0 ; i < l ; i++){
        if(S[i] == 'Z') z = i;
    }
    
    cout << z-a+1 << endl;
    return 0;
}