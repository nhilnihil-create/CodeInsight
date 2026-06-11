#include<bits/stdc++.h>
using namespace std;

int main (void){
  int h,w;
  string s[110];

  cin >> h >> w;
  for(int i = 0;i < h;i++){
    cin >> s[i];
  }

  for(int i = 0;i <= w+1;i++){
    cout << '#';
  }
  cout << '\n';

  for(int i = 0;i < h;i++){
    cout << '#' << s[i] << "#\n";
  }

  for(int i = 0;i <= w+1;i++){
    cout << '#';
  }
  cout << '\n';

  return 0;

  /*
  string型の配列を使って文字列を全て受け取ります。
  そして、for文を使って周りを#で埋めれば良いです。
  一行目と最終行は文字列の横幅+1の数だけ#を出力すれば良いです。
  その間のh行文は格納した文字列を#で挟めば良いです。

  cout 関数と一緒に出てくる''と""について少し説明します。
  ''は一文字,""は文字列を中に入れます。''に2文字以上は入らないので注意してください。
  また、改行を表す\nはセットで一文字という扱いです。
  */
}