#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>rem(4,0);
    for(int i=0;i<n;i++)
    {
        rem[v[i]%4]++;
    }
    int countzero=rem[0];
    int countone=rem[1];
    int counttwo=rem[2]>0?1:0;
    int countthree=rem[3];
    if(countzero+1>=countone+counttwo+countthree){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}