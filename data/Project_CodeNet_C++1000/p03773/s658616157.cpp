#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,Ty;
    cin >> A >> B ;
    Ty=A+B;
    if(Ty<24){
        cout << Ty <<endl;
    }
    else if(Ty>=24){
        cout << Ty -24 << endl;
    }

    return 0;
}