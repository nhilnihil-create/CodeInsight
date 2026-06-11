#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>a(N);
    for(int i=0;i<N;i++){
        cin>>a.at(i);
    }
    int count=0;
    for(int i=0;i<N;i++){
        if(a.at(a.at(i)-1)-1==i){count++;}
    }
    cout<<count/2<<endl;
    return 0;
}