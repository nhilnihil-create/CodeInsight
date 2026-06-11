#include <iostream>

using namespace std;

int main()
{
    int k,s;
    int i,j,z=0,count=0;
    cin>>k>>s;
    for( i=0;i<=k;i++){
        for( j=0;j<=k;j++){
            z=s-i-j;
            if(i>=0 && j>=0 && z>=0 && z<=k)
            count+=1;
        }
    }
    cout<<count;
    return 0;
}
