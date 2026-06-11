// B Choose Integers
#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C; // 1 <= A, B <= 100, 0 <= C < B
    cin >> A >> B >> C;
    bool ret = false;
    for (int i = 0; i < B; i ++){
        if((A*(i+1)) % B == C){
            ret = true;
        }
    }
    if (ret)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}