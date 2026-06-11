#include<iostream>

int main()
{
    int n,x=0,maxim=0;
    std::string str;
    std::cin>>n;
    std::cin.ignore();
    std::cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='I')x++;
        else x--;
        if(x>maxim){
            maxim = x;
        }
    }
    std::cout<<maxim<<std::endl;
}
