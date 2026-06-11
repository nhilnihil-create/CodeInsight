#include<iostream>
#include<string>

using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
 string s;
  
   char res1;
   int res2;
  
  for(int i=1;i<=h;i++){
   for(int j=0;j<w;j++){
     cin >> s;
     if(s=="snuke"){
       res1=j+'A';
       res2=i;
      break;
     }
   }
  }

  cout << char(res1) << res2 << endl;
}