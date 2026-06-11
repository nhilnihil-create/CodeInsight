#include <iostream>
using namespace std;

int N, freq[100100], bil, total, maks=0;

int main() {
    cin >> N;
    for (int i = 1; i<= N; i++ ){
        cin >> bil;
        freq[bil]++;
    }
    for (int i= 1;i<=100000; i++){
        total = freq[i] + freq[i+1]+ freq[i-1];
        if (maks < total){
            maks=total;
        }
    }
    cout << maks << endl;
}
