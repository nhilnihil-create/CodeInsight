#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin >>A>>B>>C;
    int D=A%B;
    int E=D;
    for(int i=0;i<1000;i++){
        E+=D;
        E%=B;
        if(E==C){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout <<"NO"<<endl;
}