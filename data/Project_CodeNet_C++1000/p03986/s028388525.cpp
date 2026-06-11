#include<bits/stdc++.h>
using namespace std;
stack<char>q;
stack<char>p;
string s;



int main(){
	cin>>s;
int i=1;q.push(s[0]);
//SSSS ST ST ST TTTT
while(i<s.size())
{
   if(q.empty())q.push(s[i]),i++;
   if(q.top()=='S'&&s[i]=='T'&&!q.empty())
   {
     	q.pop();
     	i++;
   }
   else
   {
   	  q.push(s[i]);
   	  i++;
   }	 
}
cout<<q.size()<<endl;	
	return 0;
}