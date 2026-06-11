#include<cstdio>
#include<iostream>

#define REP(i,n)   for(int i=0;i<(n);++i)

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    int n,a,min=1234567899,d=0,cnt=0;
    cin >> n >> a;
    REP(i,n){
        cin >> a;
        if(min>a){
            min = a;
        }else if(d==a-min){
            ++cnt;
        }else if(d<a-min){
            d = a - min;
            cnt=1;
        }
    }
    cout << cnt << endl;
    return 0;
}
