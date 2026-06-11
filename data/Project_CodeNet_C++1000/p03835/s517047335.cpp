#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int K,S;
    int X=0,Y=0,Z=0;
    cin >> K >> S;
    
    int count=0;
    
    for(int X=0;X<=K;X++){
        for(int Y=0;Y<=K;Y++){
                Z = S - ( X + Y );
                int sum = X + Y + Z;
                if (sum==S&&Z>=0&&Z<=K) count++;
        }
    }
    
    cout << count;
    
}
