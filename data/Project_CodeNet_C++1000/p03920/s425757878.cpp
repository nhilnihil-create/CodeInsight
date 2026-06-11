#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int score = 0;
    for(int i = 1; i <= N; i++){
        score += i;
        if(score >= N){
            for(int j = 1; j <= i; j++){
                if(score != N + j){
                    cout << j << endl; 
                }
            }
            return 0;
        }
    }
}
