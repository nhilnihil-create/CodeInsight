#include <iostream>
using namespace std;

int N, maks, X;
int a[100100];
int freq[100100];

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>a[i];
        freq[a[i]]++;
    } for(int i=0; i<=100000; i++) {
        if(freq[i]+freq[i+1]+freq[i+2]>maks) {
            maks = freq[i]+freq[i+1]+freq[i+2];
            X=i+1;
        }
    }
    cout<<maks<<endl;
}
