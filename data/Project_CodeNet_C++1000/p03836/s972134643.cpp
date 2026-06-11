#include<iostream>
#include<math.h>
#include<string>

int main()
{
    int sx,sy,tx,ty,x,y,i,j;
    std::cin>>sx>>sy>>tx>>ty;
    x = std::abs(sx-tx);
    y = std::abs(sy-ty);
    std::string str;
    for(i=0;i<y;i++){
        str.push_back('U');
        if(i==y-1){
            for(j=0;j<x;j++){
                str.push_back('R');
            }
        }
    }
    for(i=0;i<y;i++){
        str.push_back('D');
        if(i==y-1){
            for(j=0;j<x;j++){
                str.push_back('L');
            }
        }
    }
    str.push_back('L');
    for(i=0;i<y+1;i++){
        str.push_back('U');
        if(i==y){
            for(j=0;j<x+1;j++){
                str.push_back('R');
            }
        }
    }
    str.push_back('D');
    str.push_back('R');
    for(i=0;i<y+1;i++){
        str.push_back('D');
        if(i==y){
            for(j=0;j<x+1;j++){
                str.push_back('L');
            }
        }
    }
    str.push_back('U');
    std::cout<<str<<std::endl;
}
