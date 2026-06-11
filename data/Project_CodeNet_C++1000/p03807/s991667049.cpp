#include <bits/stdc++.h>


using namespace std;


int main() {

    int N, num, countOdd = 0;
    cin >> N;

    for(int i = 1; i <= N;i++){
        cin >> num;
        if(num&1){
            countOdd++;
        }
    }

    if(!(countOdd&1)){
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }



    return 0;
}
