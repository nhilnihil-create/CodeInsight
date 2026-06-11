//
//  main.cpp
//  at2201
//
//  Created by horse on 2019/4/6.
//  Copyright © 2019 horse. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
int main() {
    string a="";
    cin>>a;
    int len=a.length();
    char b[len+1];
    memset(b,0,sizeof (char)*(len+1));
    //cout<<len<<endl;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='p')
        {
            b[len-1-i]='q';
        }
        else if(a[i]=='q')
        {
            b[len-1-i]='p';
        }
        else if(a[i]=='b')
        {
            b[len-1-i]='d';
        }
        else if(a[i]=='d')
        {
            b[len-1-i]='b';
        }
        else b[len-1-i]=a[i];
    }
    //cout<<b<<endl;
    if(a==b)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
