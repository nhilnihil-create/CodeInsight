#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    string T = "";
    int count = 0; //何文字目かを記録する変数

    while(true) {
        //cout << S[count] << endl;
        if (S.size() - (count) < 10) { //最後の単語の処理
            //cout << "final roop" << endl;
            if (S.size() - (count) == 5) {  //最後の単語が5文字
                if (S[count] == 'd') T += "dream";
                else T += "erase";
            } else {
                if (S[count] == 'd') T += "dreamer";
                else T += "eraser";
            }
            //cout << T << endl;
            break;  //ループ脱出
        }


        if (S[count] == 'd') {  //dream or dreamer
            if (S[count + 5] == 'd') {
                T += "dream"; //dream かつ 次が dream or dreamer
                count += 5;
                continue;
            } else if (S[count + 7] == 'a') {
                T += "dream"; //dream かつ 次が erase or eraser
                count += 5;
                continue;
            } else {
                T += "dreamer";    //dreamer
                count += 7;
                continue;
            }

        } else if (S[count] == 'e') {   //erase or eraser
            if (S[count + 5] == 'd') {
                T += "erase";   //erase かつ 次が dream or dreamer
                count += 5;
                continue;
            } else if (S[count + 7] == 'a') {
                T += "erase";   //erase かつ 次が erase or eraser
                count += 5;
                continue;
            } else {
                T += "eraser";  //eraser
                count += 6;
                continue;
            }
        }
        //cout << T << endl;
        break;
    }

    if (S == T) cout << "YES" << endl;
    else cout << "NO" << endl;
}