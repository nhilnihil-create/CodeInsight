#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll=long long;
const int MAXN=100010;

int nlen;
int num[MAXN];

bool check(){
    auto pa=minmax_element(num+1,num+1+nlen);
    auto a=pa.first,b=pa.second;

    if(abs(*a-*b)>1)return false;

    if(*a==*b){
        if(*a==nlen-1)return true;
        else{
            //一只猫认为剩下的颜色最多为nlen-2，至少有两只猫的颜色一致。就是所有的猫至少同色两只，那么颜色不能过半
            return *a*2<=nlen;
        }
    }else{
        int singledog=0;
        int color=*b;
        for(int i=1;i<=nlen;i++)
            if(num[i]==*a){
                singledog++;
            }
        if(singledog>=color)return false;
        return 2*(color-singledog)<=nlen-singledog;
    }
}
int main(){
    ios::sync_with_stdio(false);

    cin>>nlen;
    for(int i=1;i<=nlen;i++){
        cin>>num[i];
    }

    if(check()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}