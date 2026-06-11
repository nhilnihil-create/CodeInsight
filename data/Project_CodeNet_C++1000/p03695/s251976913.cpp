#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,tmp=0,iro=0;
    cin >> n;
    vector<int> a(n);
    vector<bool> rate(8,false);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        for(int j=0;j<8;j++){
            if(400*j<=a.at(i)&&400*(j+1)>a.at(i))rate.at(j)=true;
        }
        if(a.at(i)>=3200){
            tmp++;
        }
    }
    for(int i=0;i<8;i++){
        if(rate.at(i))iro++;
    }
    cout << iro+!iro << " " << iro+tmp << endl;
    return 0;
}