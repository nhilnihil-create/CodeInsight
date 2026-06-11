#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long long count1=0,count2=0;
    long long b=0;
    for(int i=0;i<n;i++){
        b+=a[i];
        if(i%2==0&&b<=0){
            count1+=abs(b)+1;
            b=1;
        }
        else if(i%2==1&&b>=0){
            count1+=abs(b)+1;
            b=-1;
        }
    }
    long long c=0;
    for(int i=0;i<n;i++){
        c+=a[i];
        if(i%2==0&&c>=0){
            count2+=abs(c)+1;
            c=-1;
        }
        else if(i%2==1&&c<=0){
            count2+=abs(c)+1;
            c=1;
        }
    }
    cout << min(count1,count2) << endl;
}
