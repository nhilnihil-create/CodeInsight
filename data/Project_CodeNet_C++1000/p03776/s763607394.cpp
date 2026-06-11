#include <bits/stdc++.h>
using namespace std;
 

//組み合わせ nCr計算関数
vector<vector<uint64_t>> comb(int n, int r) {
  vector<vector<uint64_t>> v(n + 1,vector<uint64_t>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
 
  //データ入力
  int64_t n,a,b;
  cin>>n>>a>>b;

  vector<int64_t> v(n);
  for(int i=0;i<n;i++){
    cin>>v.at(i);
  }

  //大きい順にソート
  sort(v.begin(),v.end(),greater<int64_t>());


  //最大の平均値計算：大きい方からa個の平均
  int64_t sum=0;
  for(int i=0;i<a;i++){
    sum+=v.at(i);
  }
  //平均値出力
  cout<< fixed << setprecision(6) <<(double)sum/(double)a<<endl;


  //大きい方からa番目と同じ値の個数を調べる。a個以外で
  int64_t cnt1=0;
  for(int i=a;i<n;i++){
    if(v.at(a-1)==v.at(i))
      cnt1++;
  }

  //大きい方からa番目と同じ値の個数を調べる。a個の中で
  int64_t cnt2=0;
  for(int i=a-1;i>=0;i--){
    if(v.at(a-1)==v.at(i))
      cnt2++;
  }


    if(cnt2==a){//同じ値cnt2+cnt1個の中からa個～min(b,cnt2+cnt1)個を選ぶ組み合わせ
      int64_t sum_all=0;
      for(int i=a;i<=min(b,cnt2+cnt1);i++){
        vector<vector<uint64_t>> out(n+1, vector<uint64_t>(n+1, 0));
        out=comb(cnt2+cnt1,i);
        sum_all+=out.at(cnt2+cnt1).at(i);
      }
      cout<<sum_all<<endl;
    }else{//同じ値cnt1+cnt2個の中から,cnt2個を選ぶ
      vector<vector<uint64_t>> out(n+1, vector<uint64_t>(n+1, 0));
      out=comb(cnt1+cnt2,cnt2);
      cout<<out.at(cnt1+cnt2).at(cnt2)<<endl;
    }

	return 0;
}

