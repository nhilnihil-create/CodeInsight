#include <bits/stdc++.h>
using namespace std;
int inf = 1000000000; //10e9
 
int main() {
    
    int N, A, B;
    string S;

    cin >> N >> A >> B;
    cin >> S;

    int pass_A = 0, pass_B = 0;

    for(int i = 0; i < N; i++){
        if((pass_A + pass_B) < A+B){
            if(S[i]=='a'){
                cout << "Yes" << endl;
                pass_A++;
            } if(S[i]=='b') {
                if(pass_B<B){
                    cout << "Yes" << endl;
                    pass_B++;
                }else{
                    cout << "No" << endl;
                }
            } if(S[i]=='c') {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}