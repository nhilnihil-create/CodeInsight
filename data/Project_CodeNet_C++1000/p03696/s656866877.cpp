#include<iostream>
#include<string>

using namespace std;

int main(){
   int n, i, count1, count2, counta = 0, countb = 0;
   string s, a = "";

   cin >> n;
   cin >> s;

   i = 0;
   count1 = 0;
   count2 = 0; 
   while(i != n){
      while(i != n && s[i] == '(' ){
         count1++;
         i++;
      }

      while(i != n && s[i] == ')'){
         count2++;
         i++;
      }

      if(count1 < count2){
         counta += count2 - count1;
         count1 = 0;
         count2 = 0; 
      }
   }
   
   i = n - 1;
   count1 = 0;
   count2 = 0; 
   while(i != -1){
      while(i != -1 && s[i] == ')' ){
         count1++;
         i--;
      }

      while(i != -1 && s[i] == '('){
         count2++;
         i--;
      }

      if(count1 < count2){
         countb += count2 - count1;
         count1 = 0;
         count2 = 0; 
      }
   }

   for(int j = 0; j < counta; j++) a += '(';
   a += s;
   for(int j = 0; j < countb; j++) a += ')';

   cout << a << endl;
}