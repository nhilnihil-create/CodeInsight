#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

struct TWO{
    long long int a,b;
};

bool cmp(TWO x,TWO y){
    if(x.a!=y.a){
        return x.a<y.a;
    }else{
        return x.b<y.b;
    }
}

int main() {
    const long long int mod = 1000000007,INF=50000000000000;
    typedef pair<long long int,long long int>P;
	map<long long int, long long int>mp;
    priority_queue<P,vector<P>,greater<P> >mazuisushi;
    
    priority_queue<P>umaisushi;
	cout << fixed << setprecision(10);
    string str;
    long long int h,w,n;
    long long int a[100003],b[100003],tmp=0,fin[10]={};
    TWO num[999999];
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                if(2<=a[i]+k&&a[i]+k<=h-1&&2<=b[i]+j&&b[i]+j<=w-1){
                num[tmp].a=a[i]+k;
                num[tmp].b=b[i]+j;
                tmp++;
                }
            }
        }
    }
    sort(num,num+tmp,cmp);
    long long int count=1;
    for(int i=1;i<tmp;i++){
        if(num[i].a==num[i-1].a&&num[i].b==num[i-1].b){
            count++;
        }else{
            fin[count]++;
            count=1;
        }
    }
    if(tmp>0)fin[count]++;
    fin[0]=(h-2)*(w-2);
    for(int i=1;i<=9;i++){
        fin[0]-=fin[i];
    }
    cout<<fin[0]<<endl;
    for(int i=1;i<=9;i++){
        cout<<fin[i]<<endl;
    }
} 
