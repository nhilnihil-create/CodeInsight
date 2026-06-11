#include<bits/stdc++.h>
using namespace std;
int main(){
   int a,b,c,d;
   cin >> a >> b >> c >> d;
   vector<int> flgA(101,false);
   vector<int> flgB(101,false);
   for(int i=a; i<=b; i++){
       flgA[i]=true;
   }
   for(int i=c; i<=d; i++){
       flgB[i] = true;
   }
   int cnt=0;
   for(int i=0; i<101; i++){
       if(flgA[i] && flgB[i]) cnt++;
   }
   if(cnt!=0) cnt--;
   cout << cnt << endl;
}


