#include <iostream>
#include<bits/stdc++.h>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;
int d[10];

bool check(int x){

int a=1;

while(x>0){

    if(d[x%10]){
        a=0;
    }
    x=x/10;
}

if(a)
    return true;
else
    return false;

}


int main()
{
int n,k;
cin>>n>>k;


for(int i=1;i<=k;i++){
    int x;
    cin>>x;

    d[x]=1;

}

for(int i=n;;i++){

    if(check(i)){

       cout<<i;
       break;
       }
}


}


