#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    long long int a,b,c,minv;
    cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0){
        cout<<0<<endl;
        return 0;
    }else{
        minv=abs((a-(a/2))*b*c-(a/2)*b*c);
        minv=min(minv,abs(a*(b-(b/2))*c-a*(b/2)*c));
        minv=min(minv,abs(a*(c-(c/2))*b-a*(c/2)*b));
        cout<<minv<<endl;
        return 0;
    }
}