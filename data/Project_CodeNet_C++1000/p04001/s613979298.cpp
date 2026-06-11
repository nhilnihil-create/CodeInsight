#include <bits/stdc++.h>
using namespace std;

// 文字列の式を計算して，vector<int> totalに保存していく
void result_calc(string calc, int64_t &total) {

    // counter は数字が存在するという意味なので使い切ること
    int counter = 0; 
    int64_t result = 0;
    
    for (int i = 0; i < calc.size(); i++) {

        if (calc.at(i) == '+') {

            // cout << "counter " << counter << endl;

            while (counter > 0) {
                // 累乗
                int rank = 1;
                for (int j = 0; j < counter - 1; j++) {
                    rank *= 10LL;
                }

                result += (int64_t(calc.at(i - counter)) - 48LL) * rank;

                // cout << "i - counter " << i - counter << endl;
                // cout << "calc.at(i - counter) " << calc.at(i - counter) << endl;
                // cout << "result " << result << endl;
                counter--;
            }
        }
        else {
            counter++;
        }
    }

    // cout << "final result is " << result << endl;
    total += result;
    // cout << total << endl;
    return;
}

// 考えられる組み合わせを列挙する
void tree_calc(vector<int> &vec, int64_t &total, string calc, int i) {
    // 停止
    if (i == vec.size() - 1) {

        calc += "+"; // 番人を設定する

        // cout << "This is final calc " << calc << endl;
        result_calc(calc, total);
        return;
    }


    // // 途中処理（確認用）
    // cout << "This is calc " << calc << endl;

    // 再帰
    tree_calc(vec, total, calc + to_string(vec.at(i + 1)), i + 1);
    tree_calc(vec, total, calc + "+" + to_string(vec.at(i + 1)), i + 1);
}

// 一時的に利用するstring calcを用意する
void show_calc(vector<int> &vec, int64_t &total) {

    string calc = to_string(vec.at(0));
    tree_calc(vec, total, calc, 0);
}

int main() {

    string S;
    cin >> S;

    vector<int> vec(S.size());
    for (int i = 0; i < S.size(); i++) {
        vec.at(i) = int(S.at(i)) - 48;
    }


    int64_t total = 0;
    show_calc(vec, total);

    cout << total << endl;
}
