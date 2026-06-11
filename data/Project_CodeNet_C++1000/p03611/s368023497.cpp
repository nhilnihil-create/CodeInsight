#include <bits/stdc++.h>
using namespace std;
 
int N, banyak[100100], a, tot, maks=0;
 
int main() {
    cin >> N;
    for (int i = 1; i<= N; i++ ){
        cin >> a;
        banyak[a]++;
    }
    for (int i= 1;i<=100000; i++){
        tot = banyak[i] + banyak[i+1]+ banyak[i-1];
        if (maks < tot){
            maks=tot;
        }
    }
    cout << maks << endl;
}