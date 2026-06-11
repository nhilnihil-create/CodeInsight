#include <bits/stdc++.h>

using namespace std;

int main(){
    long double A,B,C,D,E,F,defo=-1,answ=0,anss=0;
    cin >> A >> B >> C >> D >> E >> F;
    vector<long double> water,sugar;

    for(int i=0;i<=F/100/A;i++){
        for(int j=0;j<=(F-100*i*A)/100/B;j++){
            water.push_back(100*A*i + 100*B*j);
        }
    }

    for(int i=0;i<=F/C;i++){
        for(int j=0;j<=(F-i*C)/D;j++){
            sugar.push_back(C*i+D*j);
        }
    }


    for(int i=0;i<water.size();i++){
        for(int j=0;j<sugar.size();j++){

            if(sugar[j] <= water[i]*E/100 && (water[i]+sugar[j])<=F){

                if(defo<100*sugar[j]/(water[i]+sugar[j])){
                    defo = 100*sugar[j]/(water[i]+sugar[j]);
                    answ = i;
                    anss = j;
                }
            }
        }
    }

    cout << water[answ]+sugar[anss] << " " << sugar[anss] << endl;
}