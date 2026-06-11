#include<cstdio>
#include<algorithm>
long long f(long long n){
    if(n==0)return 0;
    else if(n%2==0)return 2;
    else return 1;
}
long long g(long long a,long long b,long long c){
    long long n[3]={f(a),f(b),f(c)};
    std::sort(n,n+3);
    if(n[2]==2)return std::max(n[0]%2,n[1]%2);
    else return (n[0]+n[1]+n[2])%3;
}
int main(){
    long long i,o,t,j,l,s,z;
    scanf("%lld%lld%lld%lld%lld%lld%lld",&i,&o,&t,&j,&l,&s,&z);
    printf("%lld",i+o+j+l-g(i,j,l));
    return 0;
}