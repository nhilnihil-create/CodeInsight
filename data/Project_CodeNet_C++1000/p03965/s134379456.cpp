#include <iostream>
#include <cstdio>
#include <string>
#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

//using namespace std;


int main(){
  string moji;cin>>moji;
  int pcount;
  int len = moji.size();
  for(int i=0;i<len;i++){
    if(moji[i]=='p'){
      pcount+=1;
    }

  }
  cout<<(len/2)-pcount<<endl;
}