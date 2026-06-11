#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int count = 0;
    for(int i = 0; i <= 100; i++){
        if(i >= A && i >= C && i <= B && i <= D){
            count++;
        }
    }
    
    cout << (count == 0 ? 0 : count - 1) << endl;

}