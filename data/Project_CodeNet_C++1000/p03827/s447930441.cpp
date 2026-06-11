#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    int x = 0;
    int max = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'I') x++;
        else if(S[i] == 'D') x--;
        if(max < x) max = x;
    }
    cout << max << endl;
    return 0;
}