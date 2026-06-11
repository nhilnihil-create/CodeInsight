//
//  main.cpp
//  ABC_066_B
//
//  Created by Joe Mori on 2020/05/30.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<string>
int main() {
    std::string str;
    std::cin>>str;
    if(str.length()%2==1){
        str.erase(str.length()-1,1);
    }else str.erase(str.length()-2,2);
    while(true){
//        std::cout<<str<<std::endl;
//        std::cout<<str.substr(str.length()/2)<<" "<<str.substr(0,str.length()/2)<<std::endl;
        if(str.substr(str.length()/2)==str.substr(0,str.length()/2)){
            std::cout<<str.length()<<std::endl;
            break;
        }else{
            str.erase(str.length()-2,2);
        }
    }
    return 0;
}

