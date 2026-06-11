 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
LL K;
LL a[51];
int main(){
    cin>>K;
    REP(i,50){
        a[i]=49;
    }
    REP(i,(K%50)){
        a[i]++;
    }
    REP(i,50){
        if(a[i]!=50){
           a[i]-=(K%50);
        }
    }
    REP(i,50){
        a[i]+=(K/50);
    }
    cout<<50<<endl;
    REP(i,50){
        cout<<a[i];
        if(i!=49){
           cout<<" ";
        }else{
           cout<<endl;
        }
    }
    return 0;
}