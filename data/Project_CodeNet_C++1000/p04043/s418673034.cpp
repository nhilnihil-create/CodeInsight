#include <bits/stdc++.h>
using namespace std;

void solve(){
  std::vector<int> v(3);
  for(int i=0; i<3; i++){
    cin>>v[i];
  }
  sort(v.begin(), v.end());
  if(v[0] == 5 && v[1] == 5 && v[2] == 7){
    cout<<"YES";
  } else {
    cout<<"NO";
  }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
