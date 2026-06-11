#include<iostream>
using namespace std;

int main()
{
  int arr[3]={0},count=0,count1=0;
  cin>>arr[0]>>arr[1]>>arr[2];
  for(int i=0;i<3;i++)
  {
    if(arr[i]==5)
      count++;
    else if(arr[i]==7)
      count1++;
    else{}
  }
  if(count==2 && count1==1)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
