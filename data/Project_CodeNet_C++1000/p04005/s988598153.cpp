//
//  main.cpp
//  lab1
//
//  Created by 王黎杉 on 2020/4/24.
//  Copyright © 2020 王黎杉. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    
    long long a = 0,b = 0,c = 0;
    
    cin>>a>>b>>c;
    
    long long value[3]={a,b,c};
    
    if( a % 2 == 0 || b % 2 == 0 || c % 2 == 0 )    //只要长宽高中至少有一个是偶数，就说明长方体可以对半分
        cout<<0<<endl;
    else
    {
        sort(value, value+3);       //排序选出两个最小的边长
        
        cout<<value[0] * value[1]<<endl;        //其乘积即为答案
            
    }
    
    
    
    return 0;
}
