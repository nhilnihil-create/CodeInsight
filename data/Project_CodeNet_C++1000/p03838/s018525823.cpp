#include <iostream>

using namespace std;

int main()
{
  long int x,y,z,a;
  cin>>x>>y;


  if(x>=0&&y>=0)
  {
      if(x>y)
     {
         z=x-y+2;
         if(y==0){cout<<x-y+1;}else{cout<<z;}
     }
     else{
        z=y-x;
        cout<<z;
     }

  }
  else if (x>=0&&y<=0){
        z=-x-y+1;
        a=x+y+1;


        if(x>=-y){cout<<a;}
        else{cout<<z;}

  }
  else if(x<=0&&y>=0){if (y>=-x){cout<<x+y+1;}else if(y==0){cout<<-x;}else{cout<<-x-y+1;}}
  else if(x<=0&&y<=0){if(x>y)
     {
         z=x-y+2;
         cout<<z;
     }
     else{
        z=y-x;
        cout<<z;
     }
     }

    return 0;
}
