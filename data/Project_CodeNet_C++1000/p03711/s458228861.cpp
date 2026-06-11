#include <bits/stdc++.h>
using namespace std;
 
 
 int grouping(int input){
   if(input ==1 || input == 3 || input==5 || input==7 || input==8 || input==10 || input==12)
    return 1;
  else if(input ==2)
    return 2;
  else
    return 3;
 }

int main() {
 
  int x,y;
  cin>>x>>y;

  int x_grp = grouping(x);
  int y_grp = grouping(y);

  if(x_grp==y_grp)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

	return 0;
}

