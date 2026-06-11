#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    int max = 0;
    int max_psi = 1;
    for(int i = 0; i <=N; i++){
        if(max < (int)log2(i)){
            max = (int)log2(i);
            max_psi = i;
        }
    }
    
    cout << max_psi << endl;
}
