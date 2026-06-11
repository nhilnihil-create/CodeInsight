#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string>s(1000);
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        cout<<s[i]<<endl;
        cout<<s[i]<<endl;
    }
    return 0;
}
