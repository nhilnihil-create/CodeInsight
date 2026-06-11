#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    long long sq1,sq2;
    sq1 = A * B;
    sq2 = C * D;
    if(sq1 > sq2){
        cout << sq1 << endl;
    }else{
        cout << sq2 << endl;
    }
}