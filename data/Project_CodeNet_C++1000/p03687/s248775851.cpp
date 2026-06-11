#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    int move = 1000;
    for(char x = 'a'; x <= 'z'; x++){  //a~zまで総当たり
        string ans = {};
        string k = s;
        cnt = 0;

        for(int i = 0; i < s.size(); i++){ //終了条件の文字を作成
            ans += x;
        }
        if(s == ans){
            cout << 0 << endl;
            return 0;
        }

        while(true){
            if(k == ""){
                cnt = 0;
                break;
            }
            string n = {}; //ここに長さが1減少した文字列を用意
            cnt++; //カウントを＋１
            ans.pop_back(); //終了条件の文字数－１
            for(int i = 0; i < k.size()-1;i++){
                if(k[i] == x || k[i+1] == x){ //対応文字があったら優先
                    n += x;
                }else{ //ほかはそのまま
                    n += k[i];
                }
            }
            //cout << n << endl;
            if(n == ans){
                    move = min(move,cnt);
                    cnt = 0;
                    break;
            }
            k = n;
        }
    }

    cout << move << endl;
    return 0;
}