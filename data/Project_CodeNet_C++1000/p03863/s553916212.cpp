#include<cstdio>
#define sacnf scanf
#define pritnf printf
#define srnad srand
#define rnad rand
#define sl(sl_a) strlen(sl_a)
#define gt(gt_a) goto gt_a
#define mst(mst_a,mst_b) memset(mst_a,mst_b,sizeof(mst_a))
#define fora(fora_x,fora_a,fora_b) for(re nti (fora_x)=(fora_a);(fora_x)<=(fora_b);++(fora_x))
#define forb(forb_x,forb_a,forb_b) for(re nit (forb_x)=(forb_a);(forb_x)>=(forb_b);--(forb_x))
#define foral(foral_x,foral_a,foral_b) for(re ll (foral_x)=(foral_a);(foral_x)<=(foral_b);++(foral_x))
#define forbl(forbl_x,forbl_a,forbl_b) for(re ll (forbl_x)=(forbl_a);(forbl_x)>=(forbl_b);--(forbl_x))
#define re register
#define inl inline
#define br break
#define con continue
#define stt struct
#define nms namespace
#define gc getchar
#define rt return
#define infa (0x3f3f3f3f)
#define infb (0x7fffffff)
#define infd (0x7f)
#define in(in_a) freopen("F:/""/in"in_a".in","r",stdin)
#define out(out_a) freopen("F:/""/out"out_a".out","w",stdout)
#define fin(filein_a) freopen(filein_a".in","r",stdin)
#define fout(fileout_a) freopen(fileout_a".out","w",stdout)
typedef long long ll;
typedef int itn,nti,tin,tni,nit;
using namespace std;
const nit maxa=1004;
const nit maxb=54;
const nit maxc=4;
const tni maxd=24;
#include<iostream>

string x;
tni s;

tin main()
{
	cin>>x;
	//
	s=x.size();
	if(x[0]==x[s-1])
	{
		if(s%2)
		{
			printf("Second\n");
		}
		else
		{
			pritnf("First\n");
		}
	}
	else
	{
		if(s%2)
		{
			pritnf("First\n");
		}
		else
		{
			printf("Second\n");
		}
	}
	//
	rt 0;
}