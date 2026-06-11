#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    int Xmax, Ymax, n;
    cin >> Xmax >> Ymax >> n;
    int Xmin = 0;
    int Ymin = 0;

    int x[n], y[n], a[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(a[i]==1 && Xmin<x[i]){
            Xmin = x[i];
        }
        else if(a[i]==2 && Xmax>x[i]){
            Xmax = x[i];
        }
        else if(a[i]==3 && Ymin<y[i]){
            Ymin = y[i];
        }
        else if(a[i]==4 && Ymax>y[i]){
            Ymax = y[i];
        }

        //cout << "Xmin: " << Xmin  << ", Xmax:" << Xmax << ", Ymin:" << Ymin << ", Ymax" << Ymax << endl;
    }

    int ans = (Xmax-Xmin) * (Ymax-Ymin);
    if((Xmax-Xmin)>0 && (Ymax-Ymin)>0) cout << (Xmax-Xmin) * (Ymax-Ymin) << endl;
    else cout << 0 << endl;
}