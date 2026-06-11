#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(0<a&&a<=b){
        cout << "Positive" << endl;
    }else if(a<=b&&b<0){
        int tmp;
        tmp = b-a+1;
        if(tmp%2==0){
            cout << "Positive" << endl;
        }else{
            cout << "Negative" << endl;
        }
    }else if(a<=0&&0<=b){
        cout << "Zero" << endl;
    }
    return 0;
}


