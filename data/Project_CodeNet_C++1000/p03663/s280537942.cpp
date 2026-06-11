#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;


bool f(long n){
    cout << "? " << n << endl;
    char c;cin >> c;
    //if((n<=stol(p)&&to_string(n)<=p)||(n>stol(p)&&to_string(n)>p)) c='Y';
    //else c='N';
    //cout << " " << c << endl;
    return c=='Y'?true:false;
}

int main(){
    //string p;cin >> p;
    long k=1;
    int s;
    long n=0;
    for (int i = 0; i <= 8; i++) {
        if(!f(k*10)){
            s=i;
            int l=0,r=10;
            while(abs(r-l)>1){
                int m=(l+r)/2;
                if(f(k*m*10)){
                    r=m;
                }
                else{
                    l=m;
                }
            }
            n=k*l;
            break;
        }
        if(i==8){
            k=1;
            for (long a = 2; a < 10000000000l; a=a*10+2) {
                if(f(a)){
                    cout << "! " << k << endl;
                    return 0;
                }
                k*=10;
            }
            return 0;
        }
        k*=10;
    }
    k/=10;
    for (int i = 0; i < s; i++) {
        int l=0,r=10;
        while(abs(r-l)>1){
            int m=(l+r)/2;
            if(f((n+k*m)*10)){
                r=m;
            }
            else{
                l=m;
            }
        }
        n+=l*k;
        k/=10;
    }
    cout << "! " << n+1 << endl;
    return 0;
}


