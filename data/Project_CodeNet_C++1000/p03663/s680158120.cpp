#include <iostream>

using namespace std;

long pow10(int n){
    long ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 10;
    }
    return ans;
}

int main(){
    long cur = 1;
    int nd;
    char in;
    bool isPow10 = false;
    for(int i = 0; i <= 10; i++){
        cout << "? " << cur << endl;
        cin >> in;
        if(in == 'N'){
            nd = i;
            break;
        }
        cur *= 10;
        if(i == 10) isPow10 = true;
    }
    if(isPow10){
        for(int i = 0; i <= 10; i++){
            cout << "? " << pow10(i+1)-1 << endl;
            cin >> in;
            if(in == 'Y'){
                cout << "! " << pow10(i) << endl;
                return 0;
            }
        }
    }else{
        long l = pow10(nd-1);
        long r = pow10(nd)-1;
        long c;
        while(r-l > 1){
            c = (l+r)/2;
            cout << "? " << c*10 << endl;
            cin >> in;
            if(in == 'N') l = c;
            else r = c;
        }
        cout << "! " << r << endl;
    }
}