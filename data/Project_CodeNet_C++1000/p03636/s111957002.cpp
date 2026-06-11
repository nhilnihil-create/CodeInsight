#include <iostream>

using namespace std;

int main()
{
   string S;
   cin >> S;

   char firstChar = S.front();
   char endChar = S.back();
   int strLong = S.size() - 2;

   cout << firstChar << strLong << endChar << endl;
   return 0;

}
