#include <bits/stdc++.h>
using namespace std;

long long n,m,c,x,y,a,b,t, hasil=0, tag, j, dist;
int stick[200001];
bool mulai[200001];
bool sel[200001];
bool valid = true;

int main() {
   cin >> n;
   for (int i = 1; i <= n; i++){
       cin >> stick[i];
   }
   sort(stick+1,stick+1+n);
   for(int i = n; i>= 1; i--){
       if (stick[i] == stick[i-1]){
           a = stick[i];
           j= i-1;
           break;
       }
   }
   for (int i = j-1; i>= 1; i--){
       if (stick[i] == stick[i-1]){
           b = stick[i];
           break;
       }
   }
    cout << a*b << endl;
           
 }
    
    
    
    

    
   
