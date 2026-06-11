//
//  main.cpp
//  CF_2016予選_B
//
//  Created by Joe Mori on 2020/05/28.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<bits/stdc++.h>
int main(int argc, const char * argv[]) {
    int a,b,n,a_j=0,b_j=0;
    std::string str;
    std::cin>>n>>a>>b>>str;
    for(int i=0;i<n;i++){
        if(str.at(i)=='a'&&a_j+b_j<a+b){
            std::cout<<"Yes"<<std::endl;
            a_j++;
        }else if(str.at(i)=='b'&&b_j<b&&a_j+b_j<a+b){
            std::cout<<"Yes"<<std::endl;
            b_j++;
        }else
            std::cout<<"No"<<std::endl;
    }
    return 0;
}
