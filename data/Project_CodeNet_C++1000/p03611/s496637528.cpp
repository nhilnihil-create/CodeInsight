#include<iostream>
using namespace std;

const int N=1e5+5;
int a[N];

int main()
{
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        a[t]++;
        a[t+1]++;
        if(t>0){
            a[t-1]++;
        }
    }
    int maxn=0;
    for(int i=0;i<100005;i++){
        if(a[i]>maxn){
            maxn=a[i];
        }
    }
    cout<<maxn;
    return 0;
}