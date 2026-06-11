#include <bits/stdc++.h>
using namespace std;

int main()
{
  int s;
  double x;
    cin>>s;
    for(int i=s;i>=1;i--){
        x=log(i)/log(2);
        if(x-int(x)==0){
            cout<<i;
            break;
        }
    }

}
