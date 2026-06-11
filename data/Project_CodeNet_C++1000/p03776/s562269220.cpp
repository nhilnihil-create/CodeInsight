#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll comb(int a, int b){ //aCb
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll ans;
    double tmp;

    tmp=1.0;
    for(int i=a; i>a-b; i--){
        //cout << "comb i= " << i << endl;
        tmp *= (double) i/max(i-(a-b),1);  
        //cout << "tmp " << tmp << endl;
    }

    ans = (long long) round(tmp);

    return ans;
}

int main(){
    int A, B, N;
    cin >> N >> A >> B;
    long long v[N];
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    double vave;
    bool flag;
    int count, count_p, istart;
    ll ans;
    sort(v,v+N);
    
    vave=0.0;
    for(int i=N-A; i<N; i++){
        vave += (double) v[i];
    }
    vave = (double) vave/A;
    cout << fixed << setprecision( 7 ) << vave << endl;

    count=1;
    count_p=1;
    flag=true;
    int ii=N-1;
    while( ii>=N-A || count_p!=1  ){
    //for(int i=N-1; i>N-B; i--){
        if( ii<=0 ){
            count=count_p;
            break;
        }
        if( v[ii]!=v[ii-1] ){
            count=count_p;
            count_p=1;
            if( ii>=N-A ){
                flag=false;
                istart=ii;
                //cout << "new istart= " << istart << endl;
            }
        }else{
            count_p++;
        }
        ii--;
    }
    //cout << "ii " << ii << endl;
    //cout << "count " << count << endl;

    if( flag ){ //case only maximum: 10 10 10 10 10 10 A=3, B=5
        int C;
        C=min(B,count);
        ans=0;
        for(int i=A; i<=C; i++){
            ans+=comb(count, i);
            //cout << "i comb ans " << i << " " << comb(count, i) << " " << ans << endl;
        }
    }else{ // case: 10 10 9 9 9 9, A=4, B=4or5or6
        //cout << "A N istart A-(N-istart)= " << A << " " << N << " " << istart << " " << A-(N-istart) << endl; 
        ans=comb(count, A-(N-istart));
    }

    cout << ans << endl;

    return 0;
}