#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    string S;
    cin >> S;
    int score = 0;
    int max = 0;

    for(int i = 0; i < N; i++){
        if(S.at(i) == 'I'){
            score++;
            if(max < score){
                max = score;
            }
        }else{
            score--;
        }
    }

    cout << max << endl;
}