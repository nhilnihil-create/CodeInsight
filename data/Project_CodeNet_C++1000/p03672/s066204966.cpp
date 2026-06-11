#include<iostream>

int main(){
 std::string s;
 std::cin >> s;
 s = s.substr(0,s.length()-1);
 int len=0;
 while(1){
     if(s.length()==0) break;
     std::string t1,t2;
     if(s.length()%2==0){
        t1 = s.substr(0,s.length()/2);
        t2 = s.substr(s.length()/2);
        if(t1 == t2){ len = t1.length()*2; break;}
     }
     s = s.substr(0,s.length()-1);
}
std::cout << len;
 return 0;
}
