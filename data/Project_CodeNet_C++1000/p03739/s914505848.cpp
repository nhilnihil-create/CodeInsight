#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;

int main() {
   int n;
   cin>>n;
   vector<int>a(n);
   for(int i=0;i<n;i++){
     cin>>a[i];}
   int64_t sum1=0;int64_t count1=0;
   int64_t sum2=0;int64_t count2=0;

    //a[0]が正から始まると決めれば操作回数は自動的に決まる。
    //正からと負から始まるもの両方を調べて少ないほうを出力する。
    //累積を常に持って置き、正負に合わなければ累積分＋１の操作回数で正負を逆にできる
   for(int i=0;i<n;i++){//a[0]が正の場合の操作回数を計算
    sum1+=a[i];
    if(i%2==0){if(sum1<=0){count1+=abs(sum1)+1;sum1=1;}}
    else{if(sum1>=0){count1+=abs(sum1)+1;sum1=-1;}}
   }
   for(int i=0;i<n;i++){//a[0]が負の場合の操作回数を計算
    sum2+=a[i];
    if(i%2==0){if(sum2>=0){count2+=abs(sum2)+1;sum2=-1;}}
    else{if(sum2<=0){count2+=abs(sum2)+1;sum2=1;}}
   }
   cout<<min(count1,count2)<<endl;
return 0;}