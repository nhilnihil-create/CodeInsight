#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, flag = 0;

    cin >> a >> b;


    if(a % 3 == 0 && (a != 1 || a != 0)){
        flag = 1;


    }
    else if(b % 3 == 0 && (b != 1 || b != 0)){
        flag = 1;

    }
    else if((a + b) % 3 == 0 && (a+b != 1 || a+b != 0)){
        flag = 1;

    }

    if(flag == 0){
        cout << "Impossible" << endl;
    }
    else{
        cout << "Possible" << endl;
    }

    return 0;

}

