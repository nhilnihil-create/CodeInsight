  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <map>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)

  
  int main(){
    int n;
    cin >> n;
    map<int,int> m;
    int ans=0;

    rep(i,n){
      int tmp;
      cin >> tmp;
      m[tmp]++;
      if (m[tmp] == 3) {
        m[tmp]=1;
        ans++;
      } 
    }
    int kind=0;
    int one=0;
    int two=0;
    for (auto q:m){
      kind++;
      if (q.second == 1) one++;
      else two++;
    }
    if (two%2==0) cout << kind << endl;
    else if (two%2==1) cout << kind-1 << endl;
    return 0;
  }
