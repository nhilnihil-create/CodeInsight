#include<bits/stdc++.h>
#include<string>

using namespace std;

int A[3];

void solve() {

    int i = 0, five_counter = 0, seven_counter = 0;
    for (i = 0; i < 3 ; i++) {
        if (A[i] == 5){
            five_counter += 1;
        }
        else if (A[i] == 7) {
            seven_counter += 1;
        }
    }

    if(five_counter == 2 && seven_counter == 1) {
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

}

int main() {
    cin >> A[0] >> A[1] >> A[2];

    solve();
}