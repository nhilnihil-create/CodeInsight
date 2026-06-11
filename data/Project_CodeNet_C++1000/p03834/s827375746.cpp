#include <bits/stdc++.h>
using namespace std;

int main(){

    string a;

    cin >> a;

    for(int i = 0; i < a.length(); i++){
        if(a[i] == ','){
            a[i] = ' ';
        }
    }

    cout << a << endl;

    return 0;

}
