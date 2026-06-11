#include <iostream>
using namespace std;

string N,out_moji;
double x,T,A,AA,Z,ZZ;        

int main() {
    cin >> N;
    x = N.size();
    AA = 0;
    ZZ = 0;
        for (int i = 0; i < x; i = ++i) {        
          if(N[i] == 'A' && AA == 0) {
          A = i;
          AA = 1;
          }          
          if(N[i] == 'Z'){
          Z = i;
          ZZ = 1;
          } 
          // out_moji = out_moji + N[i];  
          //cout << i << endl;     
        }
        // for (A; A < Z; A++) {      
        //     //cout << A << endl;
        //   out_moji = out_moji + N[A];       
        // }


      
    // cout << max << endl;
   //  cout << min << endl;
   // max = max - min;
    cout << Z - A + 1 << endl;
}