#include <bits/stdc++.h>
using namespace std;

int main(){

    char c;
    int flag = 0;

    while(1){
        c = getchar();
        if(c == '9'){
            flag = 1;
        }
        else if(c == '\n'){
            break;
        }
    }

    if(flag == 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

}
