
#include <cstring> 
#include <iostream> 
using namespace std; 
  
int main() 
{ int i;
    string str;
 str.length()==19;
  cin>>str;
 
    for (int i = 0; i < 19; ++i) { 
  
        if (str[i] == ',') { 
  
            str[i] = ' '; 
        } 
    } 

   for (int i = 0; i < 19; ++i)
   {cout<<str[i];}
  
    return 0; 
} 
