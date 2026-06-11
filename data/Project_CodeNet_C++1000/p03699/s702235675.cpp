#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int s[n];
    for(int i=0;i<n;i++)cin >> s[i];
    int sum = 0;
    for(int i=0;i<n;i++)sum += s[i];
    if(sum % 10 == 0){
        sort(s,s+n);
        int i=0;
        while(s[i]%10==0)i++;
        if(i<n)sum -= s[i];
        else sum=0;
    }
    cout << sum << endl;
}