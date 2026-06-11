#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(100001, 0);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
        B.at(A.at(i))++;
    }
    
    int count_1 = 0, count_2 = 0;
    for (int i = 1; i <= 100000; i++){
        if (B.at(i) != 0){
            B.at(i) %= 2;
            if (B.at(i) == 0) count_1 ++;
            count_2++;
        }
    }
    if (count_1 % 2 ==  1) count_2--;
    cout << count_2 << endl;
}