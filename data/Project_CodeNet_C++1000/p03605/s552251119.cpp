 #include<bits/stdc++.h>
using namespace std;
int main()
{   
  char ch[2];
  int count = 0;
  cin>>ch;
  for(int i=0;i<strlen(ch);i++)
  {
    if(ch[i]=='9')
        count++;
        
  }
  if(count==0)
  cout<<"No"<<endl;
  else
  cout<<"Yes"<<endl;
  
}
