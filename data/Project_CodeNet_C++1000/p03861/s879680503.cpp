#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;



int main()
{
  long long a,b,x;
  cin>>a>>b>>x;
long long result = 0;
result =  b/x-a/x;
if(a%x == 0)
    result++;
cout<<result<<endl;


return 0;
}
