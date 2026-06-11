#include <bits/stdc++.h>
using namespace std;
int main() {
    string w;
    vector<int>cnt(26);
    cin>>w;
    if(w.size()%2==1){
        cout<<"No"<<endl;
        return 0; 
    }
    for(int i=0;i<w.size();i++){
        cnt.at(w.at(i)-'a')++;
    }
    for(int i=0;i<26;i++){
        if(cnt.at(i)%2==1){
        cout<<"No"<<endl;
        return 0;

        }
    }
    cout<<"Yes"<<endl;
    return 0;
}