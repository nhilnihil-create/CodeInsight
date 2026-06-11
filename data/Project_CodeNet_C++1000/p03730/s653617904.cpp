#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    unordered_set<int>s;
    int element=a;
    int k=2;
    bool no=true;
    while(s.find(element)==s.end()){
        if(element==(c%b)){
            no=false;
        }
        s.insert(element);
        element=a*k;
        element%=b;
        k++;
    }
    if(no){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}