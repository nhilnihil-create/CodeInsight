#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
/*
time:26m09s
wa:0
反省:一回問題を読み違えていた
考察:
• 北方向に進む移動があり、南方向に進む移動がない場合
• 南方向に進む移動があり、北方向に進む移動がない場合
• 西方向に進む移動があり、東方向に進む移動がない場合
• 東方向に進む移動があり、西方向に進む移動がない場合
は NO を出力し、それ以外の場合は YES を出力すればよい。
排他的論理和(^)を使って実装できる
少なくとも→排他的論理和
*/
int main() {
    string S;
    cin >> S;
    int n = 0;
    int w = 0;
    int s = 0;
    int e = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'N') n=1;
        else if(S[i] == 'W') w=1;
        else if(S[i] == 'S') s=1;
        else e=1;
    }
    if(!(n^s) && !(w^e)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}