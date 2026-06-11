#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    string S;
    cin >> N >> S;

    int buf = 0, max_num = 0;
    for (int i=0; i<N; i++){
        if (S.at(i) == 'I'){
            buf++;
        }
        else{
            buf--;
        }

        max_num = max(max_num, buf);
    }

    cout << max_num << endl;
    return 0;
}