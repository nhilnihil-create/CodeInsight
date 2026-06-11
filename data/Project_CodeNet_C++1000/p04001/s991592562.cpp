#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; //string型で受け取って後で数字に変換する
    cin >> s; //入力(sの長さは1~10)
    int l = s.size() - 1; //sの数字の間に入れられる+の個数の限界値
    long long ans = 0; //本当の答え。最後に出力する
    if (l == 0) { //一桁の時は
        ans = s[0] - '0'; //入力された数字を
        cout << ans << endl; //出力して
        return 0; //終了する
    }
    //以下、二桁以上の場合
    for (int bit = 0; bit < (1<<l); bit++) { //フラグが立っている場所に+を配置すると考える
        long long tempAns = s[0] - '0';
        for (int i = 0; i<l; i++) { //i番目のフラグが立っているか確かめるためのループ
            if (!(bit & (1<<i))) { //i番目のフラグが立っていない場合
                tempAns = tempAns * 10 + s[i+1] - '0'; //10倍してi+1番目の数を足す
            }
            else { //i番目のフラグが立っている場合
                ans += tempAns;
                tempAns = s[i+1] - '0';
            }
        }
        ans += tempAns; //最後までループが回ったらtempAnsが足されずに終わっているので足す
    }
    cout << ans << endl; //合計を出力
    return 0;
}