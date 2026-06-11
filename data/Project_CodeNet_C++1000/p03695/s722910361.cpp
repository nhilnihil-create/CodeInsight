#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(void)
{
    int n, c=0;
  	cin>>n;
    vector<int> color(9,0);
    rep(i,n){
        int a;
      	cin >> a;
        if(a < 3200) color[a/400]++;
        else color[8]++;
    }
    rep(i,8) if(color[i]) c++;
    if(c) cout << c;
    else cout << 1;
    cout << " " << c + color[8] << endl;
    return 0;
}