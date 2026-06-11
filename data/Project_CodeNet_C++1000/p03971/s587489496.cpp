#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;

int main(){
    int N, A, B, abroad = 1, join = 1;
    string S;
    cin >> N >> A >> B;
    cin >> S;

    rep(i, N){
        if(S[i] == 'a'){
            if(join <= A + B){
                cout << "Yes" << endl;
                join++;
            }else{
                cout << "No" << endl;
            }
        }else if(S[i] == 'b'){
            if((join <= A + B) && (abroad <= B)){
                cout << "Yes" << endl;
                join++;
                abroad++;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}