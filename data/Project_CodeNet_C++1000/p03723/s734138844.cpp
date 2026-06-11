#include <bits/stdc++.h>
using namespace std;



int main()
{
long A,B,C;
cin>>A>>B>>C;
long counter=0;
while(counter<1000000&&A%2==0&&B%2==0&&C%2==0)
{int copyA,copyB,copyC;
copyA=(B+C)/2;
copyB=(A+C)/2;
copyC=(A+B)/2;
A=copyA;
B=copyB;
C=copyC;
counter++;
}
if(counter==1000000){cout<<-1<<endl;}
else{cout<<counter<<endl;}


}
