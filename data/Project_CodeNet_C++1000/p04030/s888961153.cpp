#include <iostream>
#include <string>
#include <vector>

int main(){
   std::string s;
   std::cin >> s;
   std::vector<char> st;
   for (int i=0; i<s.size(); i++){
      if (s.at(i) != 'B'){
         st.push_back(s.at(i));
      } else{
         if (!st.empty()){
            st.pop_back();
         }
      }
   }
   for (int i=0; i<st.size(); i++){
      std::cout << st.at(i);
   }
   std::cout << std::endl;
}

