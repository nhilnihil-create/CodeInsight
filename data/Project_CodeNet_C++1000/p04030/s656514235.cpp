#include<bits/stdc++.h>
using namespace std;
int main(){
    string in,out;
    cin>>in;
    int j=0;
    for(int i=0;i<in.size();i++){
        if(in.at(i)=='0'){
            out.push_back(j);
            out.at(j)='0';
            j++;
        }else if(in.at(i)=='1'){
            out.push_back(j);
            out.at(j)='1';
            j++;
        }else if(out.size()>0){
            out.pop_back();
            j--;
        }
        
    }
    cout<<out<<endl;
}