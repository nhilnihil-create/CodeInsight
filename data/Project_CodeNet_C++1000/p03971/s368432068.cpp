#include<iostream>

int main(){
int n,a,b;
 std::cin >> n >> a >> b;
 std::string s;
 std::cin >> s;
 int pass=0,bcnt=0;
 for(int i=0;i<n;i++){
   if(s[i]=='a' && pass<a+b){
     pass++;
     std::cout << "Yes" << std::endl;
   }
   else if(s[i]=='b' && pass<a+b && bcnt<b){
    pass++;
    bcnt++;
    std::cout << "Yes" << std::endl;
   }
   else
    std::cout << "No" << std::endl;
 }
 return 0;
}
