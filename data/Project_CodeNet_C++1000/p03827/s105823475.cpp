#include<iostream>
using namespace std;

int main(){
    int x=0, maxX=0;
    int N;
    string S;
    cin >> N >> S;
    for(int i=0; i<N; i++){
        if(S[i] == 'I'){
            x++;
        }else {
            x--;
        }
        maxX = x > maxX ? x : maxX;
    }
    cout << maxX << '\n';
}
