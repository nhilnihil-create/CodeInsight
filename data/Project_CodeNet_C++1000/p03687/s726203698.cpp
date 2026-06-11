#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string s;
  cin >> s;
  //入力終了

  //sが既に単一文字のみからできているとき
  bool f = true;
  rep(i, s.size()-1 ){
    f = f*(s[i]==s[i+1]);
  }
  if(f){
    cout << 0 << endl;
    return 0;
  }

    
  int ans = 1000;
  
  //どの文字が単一文字になるかで全探索
  for(char c='a'; c<='z'; c++){
    string t1 = s;
    int cnt = 0;
    bool flag = false;
    
    //文字列が単一になるまで繰り返す
    while(!flag){
      string t2;
      //文字列t2の作成
      rep(i, t1.size()-1 ){
	//元の文字列t1にcがあればそれを連結
	if(t1[i]==c || t1[i+1]==c)
	  t2 = t2+c;
	//なければそのまま連結
	else
	  t2 = t2+t1[i];
      }

      //長さが1になれば終了
      if(t2.size() == 1)
	flag = true;
      else{
	//t2が単一文字からできているかの判定
	bool tmp_flag = true;
	rep(i, t2.size()-1 ){
	  tmp_flag = tmp_flag*(t2[i]==t2[i+1] );
	  flag = tmp_flag;
	}
      }

      t1 = t2;
      cnt++;
    } //while

    //最小値の更新
    if(cnt < ans)
      ans = cnt;
    }

  //解答
  cout << ans << endl;
  
  return 0;
}
