#include<bits/stdc++.h>
#define ll long long
#define pb push_back 
using namespace std;

int main(){
 int sx,sy,tx,ty;	
 cin >> sx >> sy >> tx >> ty;
 string a="",c="";
 int rcnt=0;
 int ucnt=0;
 
 if(sx < 0 && tx >= 0) rcnt = abs(sx) + tx;
 else if(sx >= 0 && tx >= 0) rcnt = abs(tx - sx);
 else if(sx < 0 && tx < 0) rcnt = abs(sx - tx);
 
 if(sy < 0 && ty >= 0) ucnt = abs(sy) + ty;
 else if(sy >= 0 && ty >= 0) ucnt = abs(ty - sy);
 else if(sy < 0 && ty < 0) ucnt = abs(sy - ty);
 
 //cout << rcnt << " " << ucnt;
 for(int i = 1; i <= rcnt; i++) a += 'R';
 for(int i = 1; i <= ucnt; i++) a += 'U';
 
 c += "DR";
 c += a;
 c += "UL";
 
  cout << a;
  for(int i = 0; i < (int)a.size(); i++){
   if(a[i] == 'R') cout << "L";
   else if(a[i] == 'U') cout << "D";	 
  }
  cout << c;
  for(int i = 0; i < (int)c.size(); i++){
   if(c[i] == 'R') cout << "L";
   else if(c[i] == 'U') cout << "D";	 
   else if(c[i] == 'L') cout << "R";	 
   else if(c[i] == 'D') cout << "U";	 
  }
 return 0;
}