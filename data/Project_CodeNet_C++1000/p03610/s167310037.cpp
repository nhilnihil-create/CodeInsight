#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    for(int i = 0; i < S.size(); i++){
        if(i % 2 != 1) cout << S[i]; 
    }
    cout << endl;

}
