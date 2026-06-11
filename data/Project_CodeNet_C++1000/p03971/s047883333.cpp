#include <bits/stdc++.h>
using namespace std;

int main(){
    long N,A,B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    long pass_sum=0;
    long pass_f_sum=0;
    for(int i=0; i<N; i++){
        if(S[i]=='a'){
            if(pass_sum<(A+B)){
                cout << "Yes" << endl;
                pass_sum++;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(S[i]=='b'){
            if(pass_sum<(A+B)){
                if(pass_f_sum<B){
                    cout << "Yes" << endl;
                    pass_f_sum++;
                    pass_sum++;
                }
                else{
                    cout << "No" << endl;
                }
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            cout << "No" << endl;
        }
    }
}
