#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main() {
    int n;
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
    sort(data,data+n,cmp);
    long long a1=0,a2=0;
    for(int i=0;i<n-1;i++)
    {
        if(data[i]==data[i+1])
        {
            if(a1==0)
            {
                a1=data[i];
                i++;
            } else
            {
                a2=data[i];
                break;
            }
        }
    }
    cout<<a1*a2<<endl;
}
