#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N ;
    vector<int> vec(N);

    for (int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    int a = 1, count = 0;
    for (int i = 0; i < N; i++){
        a = vec.at(a-1);
        count++;
        if (a == 2){
            cout << count << endl;
            break;
        }
    }

    if (count == N)cout << -1 << endl;

}