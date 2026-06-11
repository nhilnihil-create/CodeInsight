#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    bool a[n];
    a[0]=0;
    a[1]=0;
    t="SS";
    for(int i=1;i<n-1;i++){
        if(a[i]){
            if(s[i]=='x'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }else{
            if(s[i]=='o'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(a[i])t+='W';
        else t+='S';
    }
    for(int i=0;i<n;i++){
        if(t[i]=='S'){
            if(s[i]=='o'){
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }else{
            if(s[i]=='o'){
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }
    }

    a[0]=0;
    a[1]=1;
    t="SW";
    for(int i=1;i<n-1;i++){
        if(a[i]){
            if(s[i]=='x'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }else{
            if(s[i]=='o'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(a[i])t+='W';
        else t+='S';
    }
    for(int i=0;i<n;i++){
        if(t[i]=='S'){
            if(s[i]=='o'){
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }else{
            if(s[i]=='o'){
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }
    }

    a[0]=1;
    a[1]=0;
    t="WS";
    for(int i=1;i<n-1;i++){
        if(a[i]){
            if(s[i]=='x'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }else{
            if(s[i]=='o'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(a[i])t+='W';
        else t+='S';
    }
    for(int i=0;i<n;i++){
        if(t[i]=='S'){
            if(s[i]=='o'){
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }else{
            if(s[i]=='o'){
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }
    }
    a[0]=1;
    a[1]=1;
    t="WW";
    for(int i=1;i<n-1;i++){
        if(a[i]){
            if(s[i]=='x'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }else{
            if(s[i]=='o'){
                a[i+1]=a[i-1];
            }else{
                a[i+1]=a[i-1]^1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(a[i])t+='W';
        else t+='S';
    }
    for(int i=0;i<n;i++){
        if(t[i]=='S'){
            if(s[i]=='o'){
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }else{
            if(s[i]=='o'){
                if(t[(i-1+n)%n]!=t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }else{
                if(t[(i-1+n)%n]==t[(i+1)%n]){
                    if(i==n-1){
                        cout << t<<endl;
                        return 0;
                    }
                }else{
                    break;
                }
            }
        }
    }

    cout << -1<<endl;
    return 0;
}
