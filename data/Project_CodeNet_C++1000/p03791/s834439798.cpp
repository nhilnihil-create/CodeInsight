#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
 
using namespace std;
 
#define x first
#define y second
#define NMAX 100005
#define INF 1000000007
#define MOD 1000000007
 
int n, v[NMAX], have;
long long answer;
 
int main (){
 
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&v[i]);
    have = 0;
    answer = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] < 2 * have){
            answer = answer * have % MOD;
            //printf("%d %d %lld\n", i, have, answer);
        }
        else if(v[i] <= 2 * have){
            answer = answer * (have + 1) % MOD;
        }
        else
            have++;
    }
    //printf("%d\n", have);
    while(have){
        answer = answer * have % MOD;
        have--;
    }
    
    printf("%lld\n", answer);
    return 0;
}