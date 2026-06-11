#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int sx,sy,tx,ty;
    
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    
    int curr_x=sx-1,curr_y=sy;
    
    printf("L");
    
    while(curr_y<=ty)
    {
        printf("U");
        curr_y++;
    }
    
    while(curr_x<tx)
    {
        printf("R");
        curr_x++;
    }
    
    printf("D");
    
    curr_x=tx;
    curr_y=ty;
    
    while(curr_x>sx)
    {
        printf("L");
        curr_x--;
    }
    
    while(curr_y>sy)
    {
        printf("D");
        curr_y--;
    }
    
    printf("D");
    curr_y--;
    
    while(curr_x<=tx)
    {
        printf("R");
        curr_x++;
    }
    
    while(curr_y<ty)
    {
        printf("U");
        curr_y++;
    }
    
    printf("L");
    curr_x--;
    
    while(curr_y>sy)
    {
        printf("D");
        curr_y--;
    }
    
    while(curr_x>sx)
    {
        printf("L");
        curr_x--;
    }

    return 0;
}