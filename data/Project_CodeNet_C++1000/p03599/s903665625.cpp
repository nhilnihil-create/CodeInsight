#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<double> water;
    vector<double> sugar;
    double con=0;
    double ans1=100*a,ans2=0;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i*a*100+j*b*100<=f) water.push_back(i*a*100+j*b*100);
        }
    }
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            if(i*c+j*d<=f) sugar.push_back(i*c+j*d);
        }
    }
    sort(water.begin(),water.end());
    sort(sugar.begin(),sugar.end());
    for(int i=0;i<water.size();i++){
        for(int j=0;j<sugar.size();j++){
            if(water[i]+sugar[j]<=f&&water[i]/100*e>=sugar[j]&&(100*sugar[j])/(water[i]+sugar[j])>con){
                con=(100*sugar[j])/(water[i]+sugar[j]);
                ans1=water[i]+sugar[j];
                ans2=sugar[j];
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
}
