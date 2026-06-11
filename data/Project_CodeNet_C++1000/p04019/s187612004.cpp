
#include <iostream>

int main(int argc, const char * argv[]) {
    std::string a;
    int n,s,w,e;
    n=s=w=e=0;
    std::cin>>a;
    for(int i=0;i<a.length();i++){
        if(a.at(i)=='N'){
            n++;
        }else if(a.at(i)=='S'){
            s++;
        }else if(a.at(i)=='W'){
            w++;
        }else if(a.at(i)=='E'){
            e++;
        }
    }
    if((n>0&&s>0) || (n==0&&s==0)){
        if((w>0&&e>0)||(w==0&&e==0)){
            std::cout<<"Yes"<<std::endl;
        }else std::cout<<"No"<<std::endl;
    }else std::cout<<"No"<<std::endl;
    return 0;
}
