#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> x;
    long long tmp;
    x.push_back(-1e9-3);
    for(int i = 0;i<n;i++){
        cin >> tmp;
        x.push_back(tmp);
    }
    long l;
    cin >> l;
    x.push_back(1e12);
    int db[20][n+2];
    int db2[20][n+2];
    for(int i = 0;i<n;i++){
        db[0][i+1]=(--upper_bound(x.begin(),x.end(),x[i+1]+l)-x.begin());
        db2[0][i+1]=(lower_bound(x.begin(),x.end(),x[i+1]-l)-x.begin());
        //cout << db[0][i] << endl;
    }
    db[0][n+1]=n+1;
    db[0][n]=n+1;
    db[0][0]=n+1;
    db2[0][1]=0;
    db2[0][0]=0;
    db2[0][n+1]=0;
    for(int i = 0;i<19;i++){
        //cout << "db2[" << i << "][i]:::" << " ";
        //for(int j = 0;j<=n+1;j++) cout << db2[i][j] << " ";
        for(int j = 0;j<=n+1;j++){
            db[i+1][j]=db[i][db[i][j]];
            db2[i+1][j]=db2[i][db2[i][j]];
        }
        //cout << endl;
    }
    int q;
    cin >> q;
    long a,b;
    long ans[q];
    fill_n(ans,q,0);
    for(int i = 0;i<q;i++){
        cin >> a >> b;
        int cnt = 19;
        if(a<b){
            while(a!=b&&cnt>=0){
                if(db[cnt][a]<=b){
                    ans[i]+=pow(2,cnt);
                    a = db[cnt][a];
                }
                cnt--;
            }
            if(a!=b) ans[i]++;        
        }
        else{
            while(a!=b&&cnt>=0){
                if(db2[cnt][a]>=b){
                    ans[i]+=pow(2,cnt);
                    a = db2[cnt][a];
                }
                cnt--;
            }
            if(a!=b) ans[i]++;              
        }
    }
    for(int i = 0;i<q;i++) cout << ans[i] << endl;
}