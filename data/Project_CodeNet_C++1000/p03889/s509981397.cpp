#include<cstdio>
#define pritnf printf
#define scnaf scanf
#define retrun return
#define sizoef sizeof
#define inl inline
#define br break
#define con continue
#define mst(mst_a,mst_b) memset(mst_a,mst_b,sizeof(mst_a))
#define fora(fora_x,fora_a,fora_b) for(re nti (fora_x)=(fora_a);(fora_x)<=(fora_b);++(fora_x))
#define forb(forb_x,forb_a,forb_b) for(re nit (forb_x)=(forb_a);(forb_x)>=(forb_b);--(forb_x))
#define foral(foral_x,foral_a,foral_b) for(re ll (foral_x)=(foral_a);(foral_x)<=(foral_b);++(foral_x))
#define forbl(forbl_x,forbl_a,forbl_b) for(re ll (forbl_x)=(forbl_a);(forbl_x)>=(forbl_b);--(forbl_x))
#define re register
#define stt struct
#define nms namespace
#define gc getchar
#define sl(sl_a) strlen(sl_a)
#define gt(gt_a) goto gt_a
#define rt return
#define infa (0x3f3f3f3f)
#define infb (0x7fffffff)
#define infd (0x7f)
#define in(in_a) freopen("D:/""/in"in_a".in","r",stdin)
#define out(out_a) freopen("D:/""/out"out_a".out","w",stdout)
#define filein(filein_a) freopen(filein_a".in","r",stdin)
#define fileout(fileout_a) freopen(fileout_a".out","w",stdout)
#define file(file_a) filein(file_a);fileout(file_a)
typedef long long ll;
typedef int itn,nti,tin,tni,nit;
using namespace std;
const nit maxa=100004;
const nit maxb=1000004;
const nit maxc=4;
const tni maxd=10004;
#include<cstring>

tni s,ls;
char x[maxa];
bool f=1;

tni main()
{
    scanf("%s",x+1);
    s=sl(x+1);
    //
    ls=s>>1;
    fora(i,1,ls)
    {
        if(x[i]!=x[s-i+1])
        {
            f=0;
            br;
        }
    }
    //
    if(f)
    {
        pritnf("Yes\n");
        rt 0;
    }
    //
    if(!(s%2))
    {
        f=1;
        fora(i,1,ls)
        {
            if(((x[i]=='p')&&(x[s-i+1]!='q'))||((x[i]=='q')&&(x[s-i+1]!='p'))||((x[i]=='b')&&(x[s-i+1]!='d'))||((x[i]=='d')&&(x[s-i+1]!='b')))
            {
                f=0;
                br;
            }
        }
        //
        if(f)
        {
            printf("Yes\n");
            rt 0;
        }
    }
    //
    printf("No\n");
    rt 0;
}