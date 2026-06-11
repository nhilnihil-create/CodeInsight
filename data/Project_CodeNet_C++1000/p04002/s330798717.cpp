#include <iostream>
#include <map>
#include <utility>

using namespace std;
int main(){
    long long i,j,k,h,w,n,a,b,c[10],sum=0;
    pair<long long,long long> p;
    map <pair<long long, long long>,int> mp;
    cin >> h  >> w >> n;
    for(i=0;i<10;i++){
        c[i] = 0;
    }
    c[0] = (h-2)*(w-2);
    for(i=0;i<n;i++){
        cin >> a >> b;
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                if(a-k>0 && b-j>0 && a-k+1<h && b-j+1<w){
                    p = make_pair(a-k,b-j);
                    c[mp[p]]--;
                    mp[p]++;
                    c[mp[p]]++;
                }
            }
        }
    }
    for(i=0;i<10;i++){
        cout << c[i] << endl;
    }
}