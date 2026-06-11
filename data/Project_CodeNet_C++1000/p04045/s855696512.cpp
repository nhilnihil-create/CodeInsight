#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> D(K);
    for(int i = 0; i < K; i++) cin >> D.at(i);

    int digit, temp;
    bool check = false;

    N--;

    while(!check){
        N++;
        check = true;
        temp = N;

        while(temp != 0){
            digit = temp % 10;
            for(int i = 0; i < K; i++){
                if(digit == D.at(i)) check = false;
            }
            temp /= 10;
        }
    }

    cout << N << endl;
}
