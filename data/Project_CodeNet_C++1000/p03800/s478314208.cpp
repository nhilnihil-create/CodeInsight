#include <bits/stdc++.h>
using namespace std;
char s[100005];
bool a[100005];
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[1] = i;
            a[2] = j;
            for(int i=3;i<=n;i++){
                if(a[i-1] == 0){
                    if(s[i-1] == 'o') a[i] = a[i-2];
                    else a[i] = 1-a[i-2];
                }
                else{
                    if(s[i-1] == 'o') a[i] = 1-a[i-2];
                    else a[i] = a[i-2];
                }
            }
            bool ok = 1;
            if(a[1] == 0){
                if(s[1] == 'o'){
                    if(a[2] != a[n]) ok = 0;
                }
                else{
                    if(a[2] == a[n]) ok = 0;
                }
            }
            else{
                if(s[1] == 'o'){
                    if(a[2] == a[n]) ok = 0;
                }
                else{
                    if(a[2] != a[n]) ok = 0;
                }
            }
            if(a[n] == 0){
                if(s[n] == 'o'){
                    if(a[n-1] != a[1]) ok = 0;
                }
                else{
                    if(a[n-1] == a[1]) ok = 0;
                }
            }
            else{
                if(s[n] == 'o'){
                    if(a[n-1] == a[1]) ok = 0;
                }
                else{
                    if(a[n-1] != a[1]) ok = 0;
                }
            }
            if(ok){
                for(int i=1;i<=n;i++){
                    if(a[i] == 0) printf("S");
                    else printf("W");
                }
                return 0;
            }
        }
    }
    printf("-1\n");
}