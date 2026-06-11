#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
vector<int> t(n);
vector<int> t2(n);

            for(int i=0;i<n;i++){
        cin >> t.at(i);
       t2.at(i)=t.at(i);
    }
    int m;
    cin >> m;
    int ch;
    int ch2;
    for(int i=0;i<m;i++){
        cin >> ch >> ch2;
    t.at(ch-1)=ch2;
      int ans;
      for(int j=0;j<n;j++){
        ans+=t.at(j);
      }
    cout << ans << endl;
    ans =0;
    t.at(ch-1)=t2.at(ch-1);
    }
    
    return 0;
}