#include <iostream>
using namespace std;
int main()
{
	int x,y;
    cin >> x >> y;
    int a=0,b=0;
    switch(x)
	{
       case 1:
       a+=1;
       break;
       case 2:
       break;
       case 3:
       a+=1;
       break;
       case 4:
      b+=1;
      break;
      case 5:
      a+=1;
      break;
      case 6:
      b+=1;
      break;
      case 7:
      a+=1;
      break;
      case 8:
      a+=1;
      case 9:
      b+=1;
      break;
      case 10:
      a+=1;
      break;
      case 11:
      b+=1;
      break;
      case 12:
      a+=1;
      break;
   }
         switch(y){
       case 1:
       a+=1;
       break;
       case 2:
       break;
       case 3:
       a+=1;
       break;
       case 4:
      b+=1;
      break;
      case 5:
      a+=1;
      break;
      case 6:
      b+=1;
      break;
      case 7:
      a+=1;
      break;
      case 8:
      a+=1;
      case 9:
      b+=1;
      break;
      case 10:
      a+=1;
      break;
      case 11:
      b+=1;
      break;
      case 12:
      a+=1;
      break;
   }
   if(a==2 || b==2){
       cout << "Yes" << endl;
   }
   else{
       cout << "No" << endl;
   }
	return 0;
}