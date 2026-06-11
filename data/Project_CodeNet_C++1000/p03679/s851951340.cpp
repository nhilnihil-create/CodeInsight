#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,A,B;
    cin >> X >> A >> B;

    int h = A - B;

    if(h >= 0){
        cout << "delicious" << endl;

    }else{
        if((X - (-h)) >= 0)
            cout << "safe" << endl;
        else
            cout << "dangerous" << endl;
    }
}