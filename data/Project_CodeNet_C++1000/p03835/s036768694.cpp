#include <iostream>
using namespace std;

int main(void){
    int K,S;
    cin >> K >> S;
    int counter = 0;
    for(int i = 0 ; i <= K ; i++){
        for(int j = 0 ; j <= K ; j++){
            for(int k = 0; k <= K ; k++){
                if(S == i + j + k){
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
    return 0;
}