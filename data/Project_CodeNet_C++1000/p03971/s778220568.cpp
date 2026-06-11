#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    char P[N];
    for(int i=0; i<N; i++){cin >> P[i];}

    int candidates = 0;
    int rank_in_f = 0;
     
    for(int i=0; i<N; i++){
        char s = P[i];
        if (s=='a'){
            if(candidates < A+B){
                cout << "Yes" << endl;
                candidates += 1;
            }else{
                cout << "No" << endl;
            }
        } else if (s == 'b') {
            rank_in_f += 1;
            if((candidates < A+B) && (rank_in_f <= B) ){
                cout << "Yes" << endl;
                candidates += 1;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }


}