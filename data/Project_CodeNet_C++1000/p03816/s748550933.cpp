#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority queue
#include<deque>//double_ended queue
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]==a[i]){cnt++;}
    }
    if(cnt%2==1){cnt++;}
    cout<<n-cnt<<endl;
}