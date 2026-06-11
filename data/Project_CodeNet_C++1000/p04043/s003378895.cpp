#include <iostream>

using namespace std;

int main()
{
int a[3];
while(cin>>a[0]>>a[1]>>a[2])
{
int sum = 0,sum2 = 0;
for(int i=0;i<3;i++){
if(a[i] == 5)
sum++;
else
if(a[i] == 7)
sum2++;
}
if((sum == 2) && (sum2 == 1))
cout << "YES" <<endl;
else
cout<<"NO"<<endl;
}
    return 0;
}
