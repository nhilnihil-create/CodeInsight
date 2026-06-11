#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


struct combination {
  ll operator()(int n, int r) {
    ll num = 1;
       for(int i = 1; i <= r; i++){
           num = num * (n - i + 1) / i;
       }
       return num;
  }
};


int main(){
  int n,p;

  ll test=1;
  rep(i,20){
    test*=(i+1);
  }
  std::vector<int> a(2);
  combination c;


  std::cin >> n>>p;
  rep(i,n){
    int temp;
    std::cin >> temp;
    a[temp%2]++;
  }

  // std::cout << "偶数:" <<a[0]<<'\n';
  // std::cout << "奇数:" <<a[1]<<'\n';


  ll ans=0;



  //偶数の袋のみをとる。
  ll evenall=0;
  // std::cout << "max" <<a[0]<<'\n';
  rep(i,a[0]+1){

    // std::cout << evenall <<" "<< a[0] <<":"<< i<<'\n';
    evenall+=c(a[0],i);
  }



  if(p==0){
    ans+=evenall;
    //奇数の2n個
    for (int i = 2; i <=a[1]; i+=2) {
      ans+=c(a[1],i)*evenall;
    }
  }else{
    // std::cout << evenall << '\n';
    for (int i = 1; i <= a[1] ; i+=2) {
      ans+=c(a[1],i)*evenall;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
