#include<iostream>
#include<string>
#include<array>

int main(){
  	std::string str;
  	std::cin >> str;
  	if(str.size()==1){
      	std::cout << "0\n";
      	return 0;
    }
  	if(str.size()==2){
      	if(str.at(0) == str.at(1))
      		std::cout << "0\n";
      	else std::cout << "1\n";
      	return 0;
    }
  	std::array<int, 26> mc;
  	mc.fill(0);
  	for(int j=1;j<str.size()-1;j++){
      	char c = str.at(str.size() - 1 - j);
      	mc.at(c-'a')++;
    }
  	int ans=-1;
  	for(int i=0;i<mc.size();i++){
    if(mc.at(i) == 0) continue;
    char M = i+'a';
  	int Ms = 0, tmp=((str.at(0)==M)?0:1);
  	for(int j=1;j<str.size()-1;j++){
      	char c = str.at(j);
      	if(c!=M){
          	tmp++;
        }else{
          	if(Ms < tmp) Ms = tmp;
          	tmp=0;
        }
    }
  	if(tmp!=0 && Ms < (tmp+1)) Ms = tmp+1;
    if(ans == -1) ans = Ms;
    else if(ans > Ms) ans = Ms;
    }
  	std::cout << ans << "\n";
  	return 0;
}