#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, C;
    cin >> A >> B >> C;

    bool y = false;
    for(int i = 1; i < B; i++){
        if( i* A % B == C) {
            y=true;
            break;
        }
    }

    if(y){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
