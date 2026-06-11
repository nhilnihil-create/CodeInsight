/* Headers */
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
#include<iostream>
#include<map>
#define FOR(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define ROF(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define FORL(i,a,b,c) for(long long i=(a);i<=(b);i+=(c))
#define ROFL(i,a,b,c) for(long long i=(a);i>=(b);i-=(c))
#define FORR(i,a,b,c) for(register int i=(a);i<=(b);i+=(c))
#define ROFR(i,a,b,c) for(register int i=(a);i>=(b);i-=(c))
#define LeftChild(x) x<<1
#define RightChild(x) (x<<1)+1
#define RevEdge(x) x^1
#define FILE_IN(x) freopen(x,"r",stdin);
#define FILE_OUT(x) freopen(x,"w",stdout);
#define CLOSE_IN() fclose(stdin);
#define CLOSE_OUT() fclose(stdout);
#define IOS(x) std::ios::sync_with_stdio(x)
#define Dividing() printf("-----------------------------------\n");
namespace FastIO{
    const int BUFSIZE = 1 << 20;
    char ibuf[BUFSIZE],*is = ibuf,*its = ibuf;
    char obuf[BUFSIZE],*os = obuf,*ot = obuf + BUFSIZE;
    inline char getch(){
        if(is == its)
            its = (is = ibuf)+fread(ibuf,1,BUFSIZE,stdin);
        return (is == its)?EOF:*is++;
    }
    inline int getint(){
        int res = 0,neg = 0,ch = getch();
        while(!(isdigit(ch) || ch == '-') && ch != EOF)
            ch = getch();
        if(ch == '-'){
            neg = 1;ch = getch();
        }
        while(isdigit(ch)){
            res = (res << 3) + (res << 1)+ (ch - '0');
            ch = getch();
        }
        return neg?-res:res;
    }
    inline void flush(){
        fwrite(obuf,1,os-obuf,stdout);
        os = obuf;
    }
    inline void putch(char ch){
        *os++ = ch;
        if(os == ot)	flush();
    }
    inline void putint(int res){
        static char q[10];
        if(res==0)	putch('0');
        else if(res < 0){putch('-');res = -res;}
        int top = 0;
        while(res){
            q[top++] = res % 10 + '0';
            res /= 10;
        }
        while(top--)	putch(q[top]);
    }
    inline void space(bool x){
    	if(!x) putch('\n');
    	else putch(' ');
    }
}
inline void read(int &x){
    int rt = FastIO::getint();
    x = rt;
}
inline void print(int x,bool enter){
    FastIO::putint(x);
    FastIO::flush();
    FastIO::space(enter);
}
/* definitions */
const int MAXN = 2e7 + 10;
int n,a[MAXN];
/* functions */
namespace Solution{
    #define next n+i,n+i+1
    #define prev n-i,n-i-1
    inline bool judgeleq(int x,int y,int z){
        return a[x] <= z && a[y] <= z;
    }
    inline bool judgegeq(int x,int y,int z){
        return a[x] > z && a[y] > z;
    }
    inline bool check(int limit){
        FOR(i,0,n-1,1){
            if(judgegeq(next,limit) || judgegeq(prev,limit)) return false;
            else if(judgeleq(next,limit) || judgeleq(prev,limit)) return true;
        }
        return judgeleq(1,1,limit);
    }
    inline int binary_solve(int l,int r){
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
}
int main(int argc,char *argv[]){
    scanf("%d",&n);
    FOR(i,1,(n<<1)-1,1) scanf("%d",&a[i]);
    printf("%d\n",Solution::binary_solve(1,(n<<1)-1));
    return 0;
}
