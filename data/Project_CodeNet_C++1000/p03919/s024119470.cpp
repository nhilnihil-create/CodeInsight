#include <bits/stdc++.h>
using namespace std;
                                                                                   


int main(){
                                                                     

    int h, w, i, j, nk;

    char c, ck;

    string s;


    cin >> h >> w;


    for( i = 1 ; i <= h ; i = i + 1 ){

         c = 'A';

         for( j = 1 ; j <= w ; j = j + 1 ){

              cin >> s;

              if( s == "snuke" ){

                  ck = c;

                  nk = i;

                  }

              c += 1;

              }
 
         }


    cout << ck << nk << endl;
    

    return 0;

    }