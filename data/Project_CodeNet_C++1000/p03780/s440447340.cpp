#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_K=5000;

int main(){
    long long N, K;
    cin >> N >> K;
    long long a[N];
    long long sets[MAX_K]={}, sets_next[MAX_K]={};
    long long tmp;
    long long ans;
    long long imax, imin, ii, ians;
    bool flag;

    for(long long i=0; i<N; i++){
        cin >> a[i];
    }

    sort( a, a+N );

    ans=0;
    imin=0;
    imax=N-1;
    while( imin<=imax ){
        ii = (long long) ( imin + imax )/2;
        //cout << "imin ii imax= " << imin << " " << ii << " " << imax << endl;

        for(long long i=0; i<MAX_K; i++){
            sets[i]=0;
            sets_next[i]=0;
        }
        if( a[ii] < K ){
            sets[a[ii]]++;
            sets_next[a[ii]]++;
        }else{
            imax=ii-1;
            if( imin > imax ){
                ians=ii-1;
            }            
            continue;
        }

        vector <long long> gsets;

        for(long long i=0; i<N; i++){
            for(long long j=0; j<MAX_K; j++){

                if(i==ii){
                    break;
                }
                if( sets[j]>0 ){
                    tmp= j+a[i];
                    if( tmp >= K ){
                        //cout << "push back: ii i j tmp= " << ii << " " << i << " " << j << " " <<  tmp << endl;
                        gsets.push_back(tmp);
                    }else{
                        sets_next[tmp]++;
                    }
                }
            }

            for(long long k=0; k<MAX_K; k++ ){
                if( sets_next[k] > sets[k] ){
                    sets[k]= sets_next[k];
                }
            }

        }

        flag=true;
        for(auto v: gsets){
            if( v-a[ii] < K ){
                //cout << "ii v " << ii << " " << v << endl;
                flag=false;
            }
        }
        if(flag){
            imin=ii+1;
            if( imin > imax ){
                ians=ii;
                //cout << "last ians= " << ians << endl;
            }
        }else{
            imax=ii-1;
            if( imin > imax ){
                ians=ii-1;
            }
        }

    }

    ans = ians+1;
    cout << ans << endl;

    return 0;
}