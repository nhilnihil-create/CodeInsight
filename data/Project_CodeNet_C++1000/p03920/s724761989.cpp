#include <stdio.h>
#include <math.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
    int n;
    int s=0;
    vector<int>vec;
    cin>>n;
    for(int i=1;i<=n;i++){
        s+=i;
        vec.push_back(i);
        if(s==n){
            break;
        }
        if(s>n){
            for(int j=0;j<vec.size();j++){
                if(vec[j]==s-n){
                    vec[j]=-1;
                }
            }
            break;
        }
    }
    for(auto a:vec){
        if(a!=-1){
            cout<<a<<endl;
        }
    }
    return 0; 
}
