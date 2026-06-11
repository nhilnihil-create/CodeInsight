#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a  >> b >> c;
    
    
    int A,B,C;
    for(int i=0; ;i++){
        if(a % 2 == 1 || b % 2 == 1 || c % 2 == 1){
            cout << i << endl;
            return 0;}
        if(a == b && b == c){
        cout << -1 << endl;
        return 0;
        }
        
        
        A=a;
        B=b;
        C=c;
        a = B/2 + C/2;
        b = A/2 + C/2;
        c = A/2 + B/2;
    }
}
