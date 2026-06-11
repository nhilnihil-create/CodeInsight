#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
 int h,w;
 cin>>h>>w;
 char c[h+1][w+1];
 for(int i=1;i<=h;i++){
     for(int k=1;k<=w;k++){
         cin>>c[i][k];
     }
 }
for(int i=1;i<=2*h;i++){
    for(int k=1;k<=w;k++){
        cout<<c[(i+1)/2][k];
    }
    cout<<endl;
}


    return 0;
}
