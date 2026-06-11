#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
#include<stdlib.h>
using namespace std;

int main()
{
long x,a,b; cin>>x>>a>>b;
if(abs(x-a)<abs(x-b)) cout<<"A";
else cout<<"B";
}
