#include<bits/stdc++.h>  
#define fi first  
#define se second  
#define pb push_back  
#define CLR(A, X) memset(A, X, sizeof(A))  
using namespace std;  
  
typedef long long LL;  
typedef pair<int, int> PII;  
const double eps = 1e-10;  
int dcmp(double x){if(fabs(x)<eps) return 0; return x<0?-1:1;}  
const LL INF = 0x3f3f3f3f;  
const LL MOD = 1e9+7;  
const int N = 1e6+5;  
  
LL a[50];  
  
int main() {  
    LL k;  
    scanf("%lld", &k);  
    for(int i = 0; i < 50; i++) a[i] = i+k/50LL;  
    int x = (int)(k%50LL);  
    for(int i = 0; i < x; i++) {  
        a[i] += 51;  
        for(int j = 0; j < 50; j++) a[j]--;  
    }  
    puts("50");  
    for(int i = 0; i < 50; i++) printf("%lld%c", a[i], i==49?'\n':' ');  
    return 0;  
} 