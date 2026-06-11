#include <bits/stdc++.h>
using namespace std;

int main() {
    long long num;

    cin >> num;

    vector<long long> vec(num+1);
    for (int i = 0; i < num; i++) cin >> vec.at(i+1);

    if (num % 2 == 0){
        // 6 4 2 1 3 5
        for (int i = num; i > 1; i -= 2){
            cout << vec.at(i) << " ";
        }

        for (int i = 1; i < num; i += 2){
            cout << vec.at(i) << " ";
        }
    }else{
        // 5 3 1 2 4
        for (int i = num; i > 0; i -= 2){
            cout << vec.at(i) << " ";
        }

        for (int i = 2; i < num; i += 2){
            cout << vec.at(i) << " ";
        }
    }
}