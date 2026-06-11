#include <bits/stdc++.h>
using namespace std;
int main(){
  
  
    int a[3];
    int c5=0,c7=0;
    for(int i=0;i<3;i++){
        cin >> a[i];
        if(a[i]==5){
            c5++;
            continue;
            
        }
        else if(a[i]==7) {
            c7++;
            continue;
            
        }
    }
    if(c5==2 && c7==1) cout << "YES";
    else cout << "NO";
    
 
 
  	return 0;
}