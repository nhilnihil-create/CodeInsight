#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B,C;
    cin >> A >> B >> C ;
    bool can = false;
    for(int i=1 ; i < A*B ;i++){
        if(A*i % B ==C) can = true;
    }
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}