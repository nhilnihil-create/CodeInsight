#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    long long int a[n];
    for(int i=0;i<n;i++)cin >> a[i];

    long long int S=1000000000000000;

    for(int b=0;b<(1<<n);b++){
        if(__builtin_popcount(b)!=k) continue;

        long long int c[n];
        for(int i=0;i<n;i++)c[i]=a[i];

        long long int s=0;

        for(int i=1;i<n;i++){
            if(b&(1<<i)){
                long long int p=0;
                if(*max_element(c,c+i)>=c[i]){
                    p=*max_element(c,c+i)+1-c[i];
                    c[i]=*max_element(c,c+i)+1;
                }
                s+=p;
            }
        }

        S=min(s,S);

    }

    cout << S << endl;

}