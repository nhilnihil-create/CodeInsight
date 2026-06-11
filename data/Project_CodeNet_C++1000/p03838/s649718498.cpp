#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x,y;
    cin>>x>>y;
    const long long INF=1LL<<60;
    long long int ans1=INF,ans2=INF,ans3=INF,ans4=INF;
    long long int tmp_x=-1*x;
    long long int tmp_y=-1*y;
    if (y-x>=0) {
        ans1=y-x;
    }
    if (y-tmp_x>=0) {
        ans2=y-tmp_x+1;
    }
    if (tmp_y-x>=0) {
        ans3=tmp_y-x+1;
    }
    if (tmp_y-tmp_x>=0) {
        ans4=tmp_y-tmp_x+2;
    }
    cout<<min(ans1,min(ans2,min(ans3,ans4)))<<endl;
}