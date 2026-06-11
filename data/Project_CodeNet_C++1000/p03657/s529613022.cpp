#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int A , B ;
    cin >> A >> B ;
    int a, b ,ab ;
    a = A % 3 ;
    b = B % 3 ;
    ab = (A + B) % 3 ;

    if(a==0){
        cout << "Possible" << endl;
    }else if (b==0){
        cout << "Possible" << endl;
    }else if(ab == 0){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}