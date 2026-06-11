#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string a, b, c;
    stack<int> A, B, C;
    int cond=1;
    cin >> a >> b >> c;
    for(int i = 0; i < a.size(); i++)
        A.push(a[a.size()-i-1]);
    for(int i = 0; i < b.size(); i++)
        B.push(b[b.size()-i-1]);
    for(int i = 0; i < c.size(); i++)
        C.push(c[c.size()-i-1]);
    while(true)
    {
       if(cond==1){
           if(A.empty()){
               cout << 'A';
               return 0;
           }
           if(A.top()=='b')cond=2;
           else if(A.top()=='c')cond=3;
           A.pop();
       }
       else if(cond==2){
           if(B.empty()){
               cout << 'B';
               return 0;
           }
           if(B.top()=='a')cond=1;
           else if(B.top()=='c')cond=3;
           B.pop();
       }
       else{
           if(C.empty()){
               cout << 'C';
               return 0;
           }
           if(C.top()=='a')cond=1;
           else if(C.top()=='b')cond=2;
           C.pop();
       }
    }
}