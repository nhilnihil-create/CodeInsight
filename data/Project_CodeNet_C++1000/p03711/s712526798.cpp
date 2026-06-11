#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    int b,c;
    cin>>b>>c;
    vector<int>a(13);
    a[1]=2;
    a[2]=3;
    a[3]=2;
    a[4]=1;
    a[5]=2;
    a[6]=1;
    a[7]=2;
    a[8]=2;
    a[9]=1;
    a[10]=2;
    a[11]=1;
    a[12]=2;
    if(a[b]==a[c]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
