#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
ペアになるか
おりがみ、たて半分、よこ半分にして合致するかどうか
33
aba
cdc
aba
4 1
2 2
1 1
---3 4---
abba
caac
abba
4 2
2 2
3/2*3/2=2...4
4/2=2...2

---4 4---
abba
cddc
cddc
abba
4 4

---5 4---
acca
bddb
effe
bddb
acca
4 4
2 2
---5 5---
abeba
cdfdc
ghihg
cdfdc
abeba
4 4
2 4
1 1
H/2=2
W/2=2
2*2=4...4の数
5/2+5/2=4...2の数
1は1
*/
int main(){
  ll H,W; cin>>H>>W;
  vector<ll> str(26,0);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      char a; cin>>a;
      str[a-'a']++;
    }
  }
  ll four,two,one;
  four=(H/2)*(W/2);
  if(H%2==0 && W%2==1)
    two=H/2;
  else if(H%2==1 && W%2==0)
    two=W/2;
  else if(H%2==1 && W%2==1){
    two=H/2+W/2;
    one=1;
  }
  //four
  ll Fstr=0,Tstr=0,Ostr=0;
  for(int i=0; i<26; i++){
    Fstr+=str[i]/4;
    str[i]%=4;
  }
  for(int i=0; i<26; i++){
    Tstr+=str[i]/2;
    str[i]%=2;
  }
  for(int i=0; i<26; i++){
    Ostr+=str[i];
    str[i]=0;
  }
  if(Ostr>one || four>Fstr)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}