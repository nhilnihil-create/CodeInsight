#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int max=0;
    int index=1;
    for(int i=1;i<=n;i++)
    {
        int temp=i;
        int result=0;
        while(temp%2==0){
            result++    ;
            temp=temp/2;
        }
        if(max<result){
            max=result;
            index=i;
        }
    }
    cout<<index;    
}