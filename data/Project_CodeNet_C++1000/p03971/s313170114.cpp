#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;
    string ans;

    for(int i=0; i<N; i++){
        ans="No";
        if(S.at(i)=='a'){
            if(A+B>0){
                ans="Yes"; 
                A--;
            }
        }
        else if(S.at(i)=='b'){
            if(A+B>0 && B>0){
                ans="Yes";
                B--;
            }
        }
        cout << ans << endl;
    }
}