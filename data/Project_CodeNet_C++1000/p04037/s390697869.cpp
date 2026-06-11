#include <iostream>
#include <algorithm>

int a[100009];

int cmp(int a,int b){
    return a>b;
}
int main()
{
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        a[i]--;
    }
    std::sort(a,a+n,cmp);
    int temp=0;
    while(temp+1<n && temp+1<=a[temp+1]){
        temp++;
    }
    int dis1=a[temp]-temp;
    int dis2=0;
    for(int i=temp+1;i<n;i++){
        if(a[i]>=temp) dis2++;
    }
    if(dis1%2 || dis2%2) std::cout<<"First"<<"\n";
    else std::cout<<"Second"<<"\n";
    return 0;
}
