#include <bits/stdc++.h>
using namespace std;
int main(void){

    string a;
    cin >> a ;

    for(int i = 0; i < a.size(); i++){
        if(a.at(i) == ','){
            cout << " " ;
        } else {
            cout << a.at(i);
        }
    }
    cout << endl;

    /*
    if(a - b >= 0){
        cout << b * c + ( a - b ) * d << endl;
    } else {
        cout << a * c << endl;
    }
    */
    
    //cout << b * c + ( a - b ) * d << endl;

    return 0; 
}
