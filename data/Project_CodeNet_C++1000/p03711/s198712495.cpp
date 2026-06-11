#include<bits/stdc++.h>
using namespace std;

int main(){

    int table[13];
    table[1]=table[3]=table[5]=table[7]=table[8]=table[10]=table[12]=1;
    table[4]=table[6]=table[9]=table[11]=2;
    table[2]=3;

    int x,y;
    cin>>x>>y;
    cout<<(table[x]==table[y]?"Yes":"No")<<endl;






    return 0;
}