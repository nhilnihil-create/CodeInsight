#include<iostream>
using namespace std;

int N;
const int INF=100000000;

int main(){
    cin>>N;
    int res=-INF;
  	int count,max_i;
        for(int i=N;i>0;--i){
            count=0;
            for(int j=i;j>0;j/=2){
                if(j%2==0)++count;
                else break;
            }
                if(res<count){
                    res=count;
                    max_i=i;
                }
        }
    cout<<max_i;
}