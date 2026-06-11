#include <iostream>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    int moji_Size = S.size() - 2;
    
    cout << S[0] << moji_Size << S[S.size()-1] << endl;
    
}
