#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    int acnt=sa.size(),bcnt=sb.size(),ccnt=sc.size();
    int i=0,j=0,k=0;
    char s='a';
    while(i<=acnt&&j<=bcnt&&k<=ccnt){
        if(s=='a'){
            s=sa[i];
            i++;
        }
        else if(s=='b'){
            s=sb[j];
            j++;
        }
        else if(s=='c'){
            s=sc[k];
            k++;
        }
    }
    if(i==acnt+1) cout<<'A';
    else if(j==bcnt+1) cout<<'B';
    else if(k==ccnt+1) cout<<'C';
}