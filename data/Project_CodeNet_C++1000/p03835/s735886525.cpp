#include<iostream>
using namespace std;

int main(){
    int K, S;
    cin >> K >> S;
    int X, Y, Z, ans=0, sp=0;
    for (X=0; X<=K; X++){ //0 <= Y <= X <= Kの範囲で全探索。X != YであればXとYを交換したものも条件を満たす。
        for (Y=0;Y<=X; Y++){
            Z = S - X - Y;
            if (Z >= 0 && Z <= K){
                ans++;
                if (X == Y){
                    sp++;
                }
            }
        }
    }
    cout << 2 * ans -sp << endl;
    return 0;
}