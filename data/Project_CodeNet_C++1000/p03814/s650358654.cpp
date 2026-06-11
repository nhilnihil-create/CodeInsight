#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    int l,r;
    l = r = -1;
    
    for(int i=0;i<S.size();i++){
        if(S[i] == 'A' && l == -1){
            l = i;
        }
        if(S[i] == 'Z'){
            r = i;
        }
    }
    int ans = r - l + 1;
    
    cout << ans << endl;
    
}
