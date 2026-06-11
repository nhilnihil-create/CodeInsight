#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int total = 0;
    cin >> N;

    rep(i, N){
        int r, l;
        cin >> l >> r;
        total = total + (r-l + 1);
    }

    cout << total << endl;

}