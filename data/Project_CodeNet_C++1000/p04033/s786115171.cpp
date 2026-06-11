#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b;
    cin >> a >> b;
    if(a*b<=0){
        cout << "Zero" << endl;
    }else{
        if((a>0)&&(b>0)){
            cout << "Positive" << endl;
        }else{
            long diff = b - a;
            if(diff%2==1){
                cout << "Positive" << endl;
            }else{
                cout << "Negative" << endl;
            }
        }
    }
    return 0;
}