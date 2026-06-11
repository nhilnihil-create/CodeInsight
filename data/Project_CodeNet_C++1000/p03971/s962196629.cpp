#include<iostream>
#include<math.h>
#include<string>
using namespace std;

#define rep(i,n) for(i=0;i<N;i++)

int main(){
    int N;
    int i;
    int fo=0;
    int sum=0;
    cin>>N;
    int a,b;
    cin>>a>>b;
    string rank;
    cin>>rank;
    rep(i,N){
        if(rank[i]=='a' && sum<a+b){
            cout<< "Yes"<<endl;
            sum++;
        }else if(rank[i]=='b' && sum<a+b && fo<b){
            cout<<"Yes"<<endl;
            sum++;
            fo++;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
