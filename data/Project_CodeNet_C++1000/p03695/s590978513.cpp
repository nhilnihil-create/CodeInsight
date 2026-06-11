//
//  main.cpp
//  ABC_064_C
//
//  Created by Joe Mori on 2020/06/05.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include<bits/stdc++.h>
int main() {
    // insert code here...
    int N,min_color=0,max_color=0;
    std::cin>>N;
    std::vector<int> a(N),count(9,0);
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        if(0<a[i]&&a[i]<400){
            count[0]++;
        }else if(399<a[i]&&a[i]<800){
            count[1]++;
        }else if(799<a[i]&&a[i]<1200){
            count[2]++;
        }else if(1199<a[i]&&a[i]<1600){
            count[3]++;
        }else if(1599<a[i]&&a[i]<2000){
            count[4]++;
        }else if(1999<a[i]&&a[i]<2400){
            count[5]++;
        }else if(2399<a[i]&&a[i]<2800){
            count[6]++;
        }else if(2799<a[i]&&a[i]<3200){
            count[7]++;
        }else if(3199<a[i]){
            count[8]++;
        }
    }
    for(int i=0;i<8;i++){
        if(count[i]!=0)min_color++;
    }
    max_color=count[8]+min_color;
    if(min_color==0)min_color=1;
    std::cout<<min_color<<" "<<max_color<<std::endl;
    return 0;
}
