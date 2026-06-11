#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin >> A>>B>>C;
      if(A%2==1||B%2==1||C%2==1){
        cout <<0<<endl;
        return 0;
        }
    if(A==B&&B==C){
        cout << -1 << endl;
        return 0;
        }
  

   int sumsum=0;
   
    for(int i=0;i<1000000000000000;i++){
        int O=0,P=0,Q=0;
        O=(B+C)/2;
        P=(A+C)/2;
        Q=(A+B)/2;
        sumsum++;
        if(O%2==1||P%2==1||Q%2==1){
        cout <<sumsum<<endl;
        return 0;
        }
        A=O,B=P,C=Q;
    }    
}