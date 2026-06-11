#include <bits/stdc++.h>
using namespace std;
                                                                                   


int main(){
                                                                     

    int n, i, j;

    int s = 0;


    cin >> n;


    for( i = 1 ; s < n ; i = i + 1 ){

         s += i;
 
         }


    for( j = 1 ; j < i ; j = j + 1 ){

         if( j != s - n ) cout << j << endl;
 
         }


    return 0;

    }