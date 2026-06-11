#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    int count=0;
    for(int i=0;i<N;i++){

        if(vec.at(vec.at(i)-1)==i+1){
           count++;
        }
    }
    cout<<count/2<<endl;
    }