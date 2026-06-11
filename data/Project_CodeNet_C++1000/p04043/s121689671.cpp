#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
    int n,a(0),b(0);
    for(int i = 0;i < 3;i++){
    	cin >> n;
        if(n == 7){
        	a++;
        }else if(n == 5){
        	b++;
        }
       
    }
   if(a == 1 && b == 2){
        cout << "YES";
        }else{
        cout << "NO";
        }

}
   