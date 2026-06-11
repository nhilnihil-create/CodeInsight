#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

   int N,A; cin >> N;
   map<string,int> mp{};
   
   for(int i=0;i<N;i++){
       cin >> A;
       if(A <= 399){mp["gray"]++;}
       else if(A <= 799){mp["brown"]++;}
       else if(A <= 1199){mp["green"]++;}
       else if(A <= 1599){mp["light_blue"]++;}
       else if(A <= 1999){mp["blue"]++;}
       else if(A <= 2399){mp["yellow"]++;}
       else if(A <= 2799){mp["orange"]++;}
       else if(A <= 3199){mp["red"]++;}
       else{mp["rainbow"]++;}
   }
   
   int color = mp.size(); if(mp["rainbow"] > 0) color--;
   int minv = color; if(minv < 1) minv = 1;
   int maxv = color + mp["rainbow"];
   cout << minv << " " << maxv << endl;
}