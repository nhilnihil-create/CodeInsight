#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include <algorithm>
//include <cmath>
//#include <math.h>
using namespace std;
 
int main() {
    int K,S;
    cin >> K >> S;
    
    int ans; 
    int count=0;
    
    for(int X=0; X<=K; X++){
      for(int Y=0; Y<=K; Y++){
        //for(int Z=0; Z<=K; Z++){
             int z = S - X - Y;
              if(0 <= z && z <= K) count++;
        //}    
      }
    }
    
    cout << count << endl;
    
    return 0;
}