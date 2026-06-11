#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t a,b,c;
  cin>>a>>b>>c;


  int64_t cnt=0;

  if(a==b&&b==c&&a%2!=0){
    cnt=0;
  }
  else if(a==b&&b==c){
    cnt=-1;
  }
  else{
    while(1){
      if(a%2!=0||b%2!=0||c%2!=0)
        break;

      int64_t wk_a=a,wk_b=b,wk_c=c;

      a=wk_b/2+wk_c/2;
      b=wk_a/2+wk_c/2;
      c=wk_b/2+wk_a/2;

      cnt++;
    }
  }

  cout<<cnt<<endl;

  return 0;
}

/*
//最初
A;
B;
C;
//1回目
A=B/2+C/2
B=A/2+C/2
C=A/2+B/2
A,B,C全部同じだったら//無限回繰り返す。
A=A
B=A
C=A
//2回目
A=A/4+C/4+A/4+B/4=A/2+C/4+B/4;
B=B/4+C/4+A/4+B/4=B/2+C/4+A/4;
C=A/4+C/4+B/4+C/4=C/2+A/4+B/4;
//3回目
A=(B/4+C/8+A/8)+(C/4+A/8+B/8)=A/4+3B/8+3C/8;
B=(C/4+A/8+B/8)+(A/4+C/8+B/8)=B/4+3A/8+3C/8;
C=(B/4+C/8+A/8)+(A/4+C/8+B/8)=C/4+3B/8+3A/8;
//4回目
A=(B/8+3A/16+3C/16)+(C/8+3B/16+3A/16) =3A/8+5B/16+5C/16;
B=(A/8+3B/16+3C/16)+(C/8+3B/16+3A/16) =3B/8+5A/16+5C/16;
C=(A/8+3B/16+3C/16)+(B/8+3A/16+3C/16) =3C/8+5B/16+5A/16;
*/