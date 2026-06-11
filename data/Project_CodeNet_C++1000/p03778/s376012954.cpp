#include <bits/stdc++.h>
using namespace std;

int main() {
	int W,a,b;
    cin >> W >> a >> b;
    if(b<a){
      int c = b;
      b = a;
      a = c;
    }
    if(a <= b && b <= a+W){
      cout << 0 << endl;
    }else{
       int s = b-(a+W);
       int t = b-a;
       if(s<0){
          s = (-1)*s;
       }
       if(t<0){
          t = (-1)*t;
       }
       if(s<t){
          cout << s << endl;
       }else{
          cout << t << endl;
       }
    }
}
