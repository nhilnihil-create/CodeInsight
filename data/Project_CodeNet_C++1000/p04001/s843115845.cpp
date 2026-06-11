#include <bits/stdc++.h>
using namespace std;


long long calc(string s)
{
     int len = s.length();
     long long sum ;

     sum = stoll(s);
  
    for(int i=1;i<len;i++)
    {
        string left =s.substr(0,i);
        sum += stoll(left) * pow(2,len-i-1);
        
        string right = s.substr(i,len-i);
       
         sum += calc(right);
    
    }

   return sum;
}



int main()
{
    string s;
    cin>>s;
  
  long long sum = calc(s);
  
  cout<<sum<<endl;

}



//standlineさん参考
