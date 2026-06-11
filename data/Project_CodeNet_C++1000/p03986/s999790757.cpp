#define _CRT_SECURE_NO_DEPRECATE
#include<string>
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;


int main()
{
    stack<char>sta;
    char cha;
    while(cin>>cha)
    {
        if (sta.empty())sta.push(cha);
        else
        {
            if (cha == 'S')sta.push(cha);
            else
            {
                if (sta.top() == 'S')sta.pop();
                else sta.push(cha);
            }
        }
    }
    long long number = 0;
    while (!sta.empty())
    {
        number++;
        sta.pop();
    }
    printf("%lld", number);
}

