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
    long long a,b;
    cin>>n>>a>>b;
    long long x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    long long d[n-1];
    long long c;
    c=b/a;//距離c以下なら歩いた方がお得
    long long ans=0;
    for(int i=0;i<n-1;i++){
        if(x[i+1]-x[i]<=c){ans=ans+a*(x[i+1]-x[i]);}
        else{ans=ans+b;}
    }
    cout<<ans<<endl;
    return 0;
}