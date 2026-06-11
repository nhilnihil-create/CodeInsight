#include <bits/stdc++.h>
using namespace std;
 
std::vector<std::vector<long long>> comb(int n, int r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
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
 

  int64_t n,a,b;
  cin>>n>>a>>b;

  //組み合わせ50Ca,bだと巨大な数になるのでNG
  //大きい方からb個取れば平均は最大値となる
  //bの一番小さいのと同じのが有る分

  vector<int64_t> v(n);
  for(int i=0;i<n;i++){
    cin>>v.at(i);
  }

  sort(v.begin(),v.end(),greater<int64_t>());

  int64_t sum=0;
  for(int i=0;i<a;i++){
    sum+=v.at(i);
  }

  cout<< fixed << setprecision(6) <<(double)sum/(double)a<<endl;

  int64_t cnt=0;
  for(int i=a;i<n;i++){
    if(v.at(a-1)==v.at(i))
      cnt++;
  }

  int64_t cnt2=0;
  for(int i=a-1;i>=0;i--){
    if(v.at(a-1)==v.at(i))
      cnt2++;
  }

  if(1+cnt!=n){
    if(cnt2==a){
      int64_t sum_all2=0;
      for(int i=a;i<=min(b,cnt2+cnt);i++){
        vector<vector<long long>> out3(n + 1,vector<long long>(n + 1, 0));
        out3=comb(cnt2+cnt,i);
        sum_all2+=out3.at(cnt2+cnt).at(i);
      }
      cout<<sum_all2<<endl;
    }else{
      vector<vector<long long>> out2(n + 1,vector<long long>(n + 1, 0));
      out2=comb(cnt+cnt2,cnt2);
      cout<<out2.at(cnt+cnt2).at(cnt2)<<endl;
    }
  }
  else{
    int64_t sum_all=0;
    for(int i=a;i<=b;i++){
      vector<vector<long long>> out(n + 1,vector<long long>(n + 1, 0));
      out=comb(n,i);
      sum_all+=out.at(n).at(i);
    }

    cout<<sum_all<<endl;
  }
    

	return 0;
}

