#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
string name;
getline(cin,name);
 if (name.length() == 0) 
        return 0;
    cout << (char)toupper(name[0]);  
    for (int i = 1; i < name.length() - 1; i++) {
	
        if (name[i] == ' ') 
        {
	
            cout << (char)toupper(name[i + 1]); 
        }
    }
   return 0; 
}