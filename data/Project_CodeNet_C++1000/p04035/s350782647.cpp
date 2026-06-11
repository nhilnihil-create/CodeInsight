#include <bits/stdc++.h>
using namespace std;

int main(){   
    int n,l;
    bool f=false;
    cin >> n >> l;
    int k=1,j=0;
    vector<int> a(n);
    vector<int> co(n-1);
    cin >> a.at(0);
    for(int i=1;i<n;i++){
        cin >> a.at(i);
        if(a.at(i-1)+a.at(i)>=l){
            f=true;
            k=i;
        }
    }
    if(f){
        for(int i=1;i<k;i++){
            co.at(i-1)=i;
            j=i;
        }
        for(int i=n-1;i>=k;i--,j++){
            co.at(j)=i;
        }
        cout << "Possible" << endl;
        for(int i=0;i<n-1;i++){
            cout << co.at(i) << endl;
        }
    }else{
        cout << "Impossible" << endl;
    }
}