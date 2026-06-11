#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
bool nxt = true; ///true - first, false - second

int gcd(int a, int b){
if (b<a) swap(a,b);
if (a==0) return b;
else return (gcd(b%a,a));
}

bool winstate(){
int numeven = 0;
for (int x = 0; x<n; x++){
    if (arr[x]%2==0) numeven++;
}
return numeven%2==1;
}

bool losestate(){
int numeven = 0;
int numodd = 0;
for (int x = 0; x<n; x++){
    if (arr[x]%2==0) numeven++;
    else numodd++;
}
return (numeven%2==0) && (numodd!=1);
}

int main(){
scanf("%d",&n);
for (int x = 0; x<n; x++){
    scanf("%d",&arr[x]);
}
while (true){
    if (winstate()){
        printf(nxt?"First":"Second");
        return 0;
    }
    if (losestate()){
        printf(nxt?"Second":"First");
        return 0;
    }
    int d = 0;
    for (int x = 0; x<n; x++){
        if (arr[x]%2==1) arr[x]--;
        if (arr[x]==0){
            printf(nxt?"Second":"First");
            return 0;
        }
        d = gcd(d,arr[x]);
    }
    for (int x = 0; x<n; x++){
        arr[x] /= d;
    }
    nxt = (!nxt);
}
}
