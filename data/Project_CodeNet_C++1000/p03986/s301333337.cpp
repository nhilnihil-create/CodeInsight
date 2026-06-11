#include<iostream>
#include<string>

int main(){
  	std::string str;
  	std::cin >> str;
  	int stackS=0, dub=0;
  	bool prevT=false;
  	for(auto&&c : str){
      	if(c=='S'){
          	if(prevT){
              	prevT=false;
            }
          	stackS++;
        }
      	else if(c=='T'){
          	if(stackS>0){
              	stackS--;
              	dub++;
            }
          	prevT=true;
        }
    }
  	std::cout << str.size() - dub*2 << std::endl;
  	return 0;
}