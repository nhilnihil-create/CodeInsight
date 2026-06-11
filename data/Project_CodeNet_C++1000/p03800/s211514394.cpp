#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int zz=1 ; zz<=t ; zz++)
#define PRINT_CASE printf("Case %d: ",zz)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)1e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

char str[maxn], ans[maxn];
int n;

bool check(){

    for(int i=3 ; i<=n ; i++){
        if(ans[i-1]=='S'){
            if(str[i-1]=='o'){
                if(ans[i-2]=='S') ans[i]='S';
                else ans[i]='W';
            }else {
                if(ans[i-2]=='S') ans[i]='W';
                else ans[i]='S';
            }
        }else {
            if(str[i-1]=='o'){
                if(ans[i-2]=='S') ans[i]='W';
                else ans[i]='S';
            }else {
                if(ans[i-2]=='S') ans[i]='S';
                else ans[i]='W';
            }
        }
    }

    if(ans[1]=='S'){
        if(str[1]=='o'){
            if(ans[2]!=ans[n]) return false;
        }else{
            if(ans[2]==ans[n]) return false;
        }
    }else {
        if(str[1]=='o'){
            if(ans[2]==ans[n]) return false;
        }else {
            if(ans[2]!=ans[n]) return false;
        }
    }


    if(ans[n]=='S'){
        if(str[n]=='o'){
            if(ans[n-1]!=ans[1]) return false;
        }else {
            if(ans[n-1]==ans[1]) return false;
        }
    }else {
        if(str[n]=='o'){
            if(ans[n-1]==ans[1]) return false;
        }else {
            if(ans[n-1]!=ans[1]) return false;
        }
    }
    return true;
}

void printAns(){
    f1(i,n){
        printf("%c", ans[i]);
    }
    printf("\n");
}
int main() {
    CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sf(n);
    scanf("%s", str+1);

    ans[1]='S';
    ans[2]='S';
    if(check()){
        printAns();
        return 0;
    }
    ans[1]='W';
    ans[2]='W';
    if(check()){
        printAns();
        return 0;
    }

    ans[1]='S';
    ans[2]='W';
    if(check()){
        printAns();
        return 0;
    }
    ans[1]='W';
    ans[2]='S';
    if(check()){
        printAns();
        return 0;
    }

    printf("-1");



    return 0;
}
