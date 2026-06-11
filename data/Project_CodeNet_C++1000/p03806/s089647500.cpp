#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include<queue>
#include <sstream>
#include <set>
#include<stack>
#include <utility>

const long long MOD = 1000000007;
using namespace std;
typedef long long llong;

//int isalpha(char ch): ch がアルファベットなら true を返す
//int isdigit(char ch): ch が数字なら true を返す
//int islower(char ch): ch が小文字なら true を返す
//int isupper(char ch): ch が大文字なら true を返す
//int tolower(char ch): ch の小文字を返す
//int toupper(char ch): ch の大文字を返す

//string型
//size()	文字数を返す
//Insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//c_str()変換
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());
//map<type, type> dict;で宣言
//グラフ理論用変数
//vector<vector<llong> > graph(N);

//ソート
//降順sort(v.begin(), v.end(), std::greater<Type>());

//大文字から小文字へんかん
//w[i] = w[i]-'A'+'a';

//vector
//assignメソッド　引数：サイズ、値
//与えられたサイズと値でvectorを初期化する

//queueクラス
//find()次に取り出す値の表示をする。
//pop()値を取り出す。戻り値はなし
//push()キューに値をプッシュする

//priority_queueクラス

//切り上げ
//ceil
//floor

typedef struct _MedicineInfo{
    llong a;
    llong b;
    llong c;
}MedicineInfo;

int main(){
    llong N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<MedicineInfo> Table(N+1);
    for(int i=1; i<=N; i++){
        cin >> Table[i].a >> Table[i].b >> Table[i].c;
    }
    llong MAX_SIZE = 500;
    vector<vector<vector<llong> > > dp(N+1, vector<vector<llong> >(MAX_SIZE+1, vector<llong>(MAX_SIZE+1,MOD)));
    dp[0][0][0] = 0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=MAX_SIZE; j++){
            for(int k=0; k<=MAX_SIZE; k++){
                if(j-Table[i].a<0){
                    dp[i][j][k] = dp[i-1][j][k];
                    continue;
                }
                if(k-Table[i].b<0){
                    dp[i][j][k] = dp[i-1][j][k];
                    continue;
                }
                dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-Table[i].a][k-Table[i].b]+Table[i].c);
            }
        }
    }
    llong ans=MOD;
    for(int i=1; i<=MAX_SIZE; i++){
        for(int j=1; j<=MAX_SIZE; j++){
            if((Ma*j)==(i*Mb)){
                ans = min(ans, dp[N][i][j]);
            }
        }
    }
    if(ans==MOD){
        cout << -1 << endl;
        exit(0);
    }
    cout << ans << endl;
    return 0; 
}
