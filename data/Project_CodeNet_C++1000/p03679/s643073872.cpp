#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,A,B;
    string S[3]={"delicious","safe","dangerous"};
    cin>>X>>A>>B;
    if(A>=B){
        cout<<S[0]<<endl;
    }else if(B-A<=X){
        cout<<S[1]<<endl;
    }else{
        cout<<S[2]<<endl;
    }
    return 0;
}