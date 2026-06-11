#include <bits/stdc++.h>
using namespace std;

int main() {
   string S;
   cin >> S;
   queue<char> q;
   for (int i=0; i<S.size(); i++) {
       q.push(S[i]);
   }
   bool aa;
   bool bb=false;
   while(!q.empty()) {
       char a[6];
       bool b,c;
       aa=false;
       b=true;c=true;
       for (int i=0; i<5; i++) {
           a[i]=q.front();
           if (bb && i==2) {
               if (a[0]=='e' && a[1]=='r' && a[2]!='a') {
                   aa=true;bb=false;break;
               }
           }
           q.pop();
           if (i==1 && q.empty() && bb) {
               if (a[0]=='e' && a[1]=='r') {
                   cout << "YES" << endl;
                   aa=true;break;
               }
           }
           if (i!=4 && q.empty()) {
               cout << "NO" << endl;aa=true;break;
           }
       }
       if (aa) continue;
       if (a[0]!='d') b=false;
       if (a[1]!='r') b=false;
       if (a[2]!='e') b=false;
       if (a[3]!='a') b=false;
       if (a[4]!='m') b=false;
       if (a[0]!='e') c=false;
       if (a[1]!='r') c=false;
       if (a[2]!='a') c=false;
       if (a[3]!='s') c=false;
       if (a[4]!='e') c=false;
       bb=b;
       if ((!b) && (!c)) {
           cout << "NO" << endl;break;
       }
       if (c && q.front()=='r' && (!q.empty())) {
           q.pop();
       }
       if (q.empty()) cout << "YES" << endl;
   }
}