#include <iostream>
#include <vector>
using namespace std;

int main(){
    string S;
    cin >> S;
    int s = 0;
    int ans = 0;
    for(int i = 0; i < S.size();i++){
        if(S[i] == 'S'){
            s++;
        }else if(S[i] == 'T'){
            if(s > 0){
                ans++;
                s--;
            }
        }
        //cout << ans << endl;
    }
    cout <<S.size() - ans*2 << endl;
    
}