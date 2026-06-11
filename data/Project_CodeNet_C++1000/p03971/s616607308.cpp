#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, N;
    string S;
    cin >> N >> A >> B;
    cin >> S;
    string c;
    int p = 0;
    int b = 0;
    //char c;

    for (int i=0; i < S.size(); i++){
        //c = S.at(i);
        if(S.at(i) == 'a'){
            if(p < A+B){
            cout << "Yes" << endl;
            p++;
            }else{
                cout << "No" << endl;
            }
    }else if(S.at(i) == 'b'){ 
         if(p < A+B && b < B){
            cout << "Yes" << endl;
            p++;
            b++;
         }else{
            cout << "No" << endl;
         }
    }else{
            cout << "No" << endl;
    }

    }
}
