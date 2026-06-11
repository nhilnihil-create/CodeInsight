#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B,C,Ahako,Bhako,count=0;

    cin >> A >> B >> C;

    while(true){

        if((A % 2) != 0 || (B % 2) != 0 || (C % 2) != 0){
            cout << count << endl;
            break;
        }

        Ahako = A / 2;
        Bhako = B / 2;
        A = Bhako + C / 2;
        B = Ahako + C / 2;
        C = Ahako + Bhako;
        count++;

        
        if(A == B && A == C){
            cout << -1 << endl;
            break;
        }
    }
}