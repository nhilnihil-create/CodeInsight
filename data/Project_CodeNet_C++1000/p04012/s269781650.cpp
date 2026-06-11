#include <bits/stdc++.h>
using namespace std;
int main() {

   char str[100];
   cin >> str;
   int lowAlphabet[26] = {0}, j;
   for(int i=0; str[i]!='\0'; i++)
   {
      if (str[i] >= 'a' && str[i] <= 'z')
        {
         j = str[i] - 'a';
         ++lowAlphabet[j];
        }
   }
   int count1=0,count2=0;
   for (int i = 0; i < 26; i++)
   {
       if(lowAlphabet[i]!=0 && lowAlphabet[i]%2==0)
        count1++;
        else if(lowAlphabet[i]!=0 && lowAlphabet[i]%2!=0)
        count2++;
   }
   if(count1!=0&&count2==0)
    cout << "Yes";
   else
    cout << "No";

   return 0;
}
