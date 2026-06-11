#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    string N ;
    cin >> N ;

    size_t l = N.length();
    bool jud = false ;
    int count = 0; 
    
       
    for(int i = 0 ; i < l / 2; i++ ){
       
        if( N[i] == N[l-i-1]){
           count++;
        }
    }
       if(count == l / 2 ){
           jud = true ; 
       }
    
    if(jud == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}