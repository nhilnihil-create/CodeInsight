#include"bits/stdc++.h"
using namespace std;

int main(){
    string N;
    cin>>N;
    int size=N.size();
    long result=0;

    for(int tmp=0;tmp<(1<<(size-1));tmp++){
        bitset<9>n(tmp);
        long sum=0;
        int z=0;
        for(int i = 0; i < size-1; i++){
            if(n.test(i)){
                string x=N.substr(z,i+1-z);
                long y=stol(x);
                sum+=y;
                z=i+1;
            }
        }
        string t=N.substr(z);
        long s=stol(t);
        sum+=s;
        result+=sum;
    }
    cout<<result<<endl;
}