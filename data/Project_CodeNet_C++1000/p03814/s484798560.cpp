#include<iostream>

int main()
{
    std::string str;
    std::cin>>str;
    int i,a,b;
    for(i=0;i<str.size();i++){
        if(str[i]=='A'){
            a = i;
            break;
        }
    }
    for(i=str.size()-1;i>=0;i--){
        if(str[i]=='Z'){
            b = i;
            break;
        }
    }
    std::cout<<b-a+1<<std::endl;
}
