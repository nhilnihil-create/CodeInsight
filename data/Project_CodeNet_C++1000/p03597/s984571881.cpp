#include<iostream>
using namespace std;
int main()
{
   int a;
   int b;
   cin >> a >> b;
   int sum = a * a;
   int white = sum - b;
   cout << white << endl;
   return 0;
}