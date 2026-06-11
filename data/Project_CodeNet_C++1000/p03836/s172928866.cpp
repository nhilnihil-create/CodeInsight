#include <bits/stdc++.h>
using namespace std;
int main(void){
   int sx,sy,tx,ty;
   cin >> sx >> sy >> tx >> ty;
   int difx = tx - sx, dify = ty - sy;
   cout << string(difx,'R') << string(dify,'U'); 
   cout << string(difx,'L') << string(dify,'D');
   cout << 'D' << string(difx+1,'R') << string(dify+1,'U') << 'L';
   cout << 'U' << string(difx+1,'L') << string(dify+1,'D') << 'R';
   cout << endl;
}