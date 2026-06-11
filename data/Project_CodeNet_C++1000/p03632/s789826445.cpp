#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;

    cin >> A >> B >> C >> D;

    int time = 0;
    if(C < B && D > A){
        if(A < C){
            if(B < D)
                time = B - C;
            else
                time = D - C;
        }
        else if(A > C){
            if(B > D)
                time = D - A;
            else 
                time = B - A;
        }else{
            if(B > D)
                time = D - A;
            else
            {
                time = B - A;
            }
        }
    }else{
        time = 0;
    }
    
    cout << time  << endl;

}