#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    string S; cin>>S;
    int counter=0;
    int counter1=0;
    int counter2=0;
    int answer=0;
    int a=0;
    for(int i=0; i<S.size();i++){
    if(S.at(i)=='N')
    counter++;
    if(S.at(i)=='W')
    counter1++;
    if(S.at(i)=='S')
    counter2++;
    if(S.at(i)=='E')
    answer++;
    }
    if(counter==0){
    a++;}
    if(counter1==0){
    a++;}
    if(counter2==0){
    a++;}
    if(answer==0){
    a++;}
    if(a==3||a==1){
    cout<<"No"<<endl;}
    else
    if(counter==0||counter2==0||counter1==0||answer==0){
    if((counter==0&&counter2==0)||(counter1==0&&answer==0))
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;}
    
    else
    cout<<"Yes"<<endl;
}
    
