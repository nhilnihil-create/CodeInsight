#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string x;
    cin>>x;
    int temp[30];
    for(int i=0;i<30;i++){
        temp[i]=0;
    }
    for(int i=0;i<x.length();i++){
        temp[x[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if (temp[i]%2!=0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}