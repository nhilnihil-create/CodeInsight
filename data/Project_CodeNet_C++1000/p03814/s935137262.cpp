#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int res = 0, found = 0, p = 0;

int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'A' && found == 0){
            res = 0;
            //cout << "test" << endl;
            found = 1;
        }
        if(str[i] == 'Z' && found != 0){
            res++;
            p = res;
        }
        else if(found != 0){
            res++;
        }

    }
    cout << p << endl;
}