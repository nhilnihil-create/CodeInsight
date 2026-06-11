#include <iostream>
#include <string>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int ans = 0;
    for(int i=0;i+1<S.size();i++){
        if(S[i] != S[i+1])ans++;
    }
    cout << ans << endl;
}
