#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    
    int K, S;
    cin >> K >> S;
    
    int ans = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= K; j++){
            int nokori = S - (i + j);
            if(nokori >= 0 && nokori <= K) ans++;
        }
    }
    
    cout << ans << endl;
}
