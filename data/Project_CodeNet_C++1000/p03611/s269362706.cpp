#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
int a[100030]={0};

    int X;
    while(N--){
        cin>>X;
        a[X]++;
        a[X-1]++;
        a[X+1]++;
    }

int max_value=0;
        for(int i=0;i<=100000;++i){
            if(max_value<a[i])max_value=a[i];
        }
cout<<max_value;

}

