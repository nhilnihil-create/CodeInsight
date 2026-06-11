#include <iostream>
#include<bits/stdc++.h>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;


int main()
{

string w;
cin>>w;
int a=1;

for(int i=0;i<w.size();i++){
    int c=1;
    for(int j=0;j<w.size();j++){

    if(j==i)
        continue;

        if(w[j]==w[i])
            c++;
    }
   if(c%2!=0){
        a=0;
        break;
    }

}
if(a==1)
    cout<<"Yes";
else
    cout<<"No";


}


