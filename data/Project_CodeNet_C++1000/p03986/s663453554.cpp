#include <iostream>
#include <cstring>
#include<cmath>
#include<string>
#include <algorithm>
#include <stack> 
using namespace std; 
string s1,s2;
stack<int> sp;
int main(int argc, char** argv) {
   s2.push_back('S');
   s2.push_back('T');
   cin>>s1;
   int a;
   int b;
   int p=0;
    
   sp.push(p);
   p++;
   while(p<s1.size())
   {
    if(s1[p]=='T'&&sp.size()!=0&&s1[sp.top()]=='S')
    { sp.pop();p++;	
	  
	}
	else
	{sp.push(p);
	 p++;
	}
    
   }
   cout<<sp.size()<<endl;
	return 0;
}