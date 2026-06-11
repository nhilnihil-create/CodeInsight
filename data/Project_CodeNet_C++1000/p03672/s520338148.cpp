#include <bits/stdc++.h>
using namespace std;

bool chk(string s,int i){

        	int mid = i/2;

        	for(int start = 0;start<mid;start++)
        	{
        		 if(s[start]!=s[start+mid])
        		  return false; 
        	}
        	return true;

        }
int main(void)
{
    string s;
    cin>>s;
    int len = s.length();
    int res = 0;
   for(int i = len-1;i>=0;i--)
   {

        if(i%2==0 && chk(s,i))
           {
           	 res = i;
           	 break;
           }
   }

   cout<<res<<endl;

}