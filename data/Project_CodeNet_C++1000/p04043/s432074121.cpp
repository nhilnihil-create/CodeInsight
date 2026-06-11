#include <iostream>
using namespace std;

int main(){
    int abc[3];
    int five = 0;
    int seven = 0;
    cin >> abc[0] >> abc[1] >> abc[2];
    for(const auto& num: abc){
        if(num == 5){
            five ++;
        }
        if(num == 7){
            seven ++;
        }
    }

    if(five == 2 && seven == 1){
        cout << "YES";
    }else{
        cout << "NO";
    }
}