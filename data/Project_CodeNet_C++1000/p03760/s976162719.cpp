#include<bits/stdc++.h>
using namespace std;
int main(){
    string o,e;
    cin>>o;
    cin>>e;
    string ans="";//コノジテンデハ、ハイレツノオオキサハ０デアル
    int ln=o.size()+e.size();
    //ans.resize(ln);
    for(int i=0;i<ln;i++){
        if(i%2==0){ 
            ans.push_back(i);
            ans.at(i)=o.at(i/2);

        }
        if(i%2==1){ 
            ans.push_back(i);
            ans.at(i)=e.at(i/2);}
    }
    cout<<ans<<endl;
}