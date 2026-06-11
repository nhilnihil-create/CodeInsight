//### In The Name Of GOD ###

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())

const int MOD = 1000000007;
const int INF = 30 * 1000 + 20;
const int MAXN = 2 * 100000 + 20;
const int MLOG = 18;
const int NMAX = 60;

int fact[MAXN], infc[MAXN];

int power(int x, int y){
    if (y == 0)
        return 1;
    int p = power(x, y/2) % MOD;
    p = (p * p) % MOD;
    return (y%2 == 0)? p : (x * p) % MOD;
}
int inv(int a){
	return power(a, MOD-2);
}

int find_f(int a, int b, int c, int d){//from point (a, b) to point (c, d)
	//cout << a << ' ' << b << ' ' << c << ' ' << d << "here \n";
	int x = c - a; 
	int y = d - b;
	y = y + x;
	//cout << x << " from " << y << ' '<<fact[y] <<' '<< infc[x] <<' '<< infc[y] << endl;
	return fact[y] * infc[x] % MOD * infc[y-x] % MOD;
}

signed main(){
	fact[0] = 1;
	infc[0] = 1;
	for(int i = 1; i < MAXN; i++){
		fact[i] = (fact[i-1]*i) % MOD;
		infc[i] = inv(fact[i]);
		//cout << i << ' ' << fact[i] << ' ' << infc[i] << ' ' << (fact[i] * infc[i]) % MOD<< endl;
	}
	int H, W;
	int h, w;
	int ans = 0;
	cin >> H >> W >> h >> w;
	for(int i = 0; i < H-h; i++){
		ans += find_f(0, 0, i, w-1) * find_f(i, w, H-1, W-1);
		ans %= MOD;
	}
	cout << ans;
}














/*    ___           ___           ___           ___           ___           ___           ___          _____
     /__/\         /  /\         /__/\         /  /\         /__/\         /__/\         /  /\        /  /::\
    |  |::\       /  /::\        \  \:\       /  /::\       |  |::\       |  |::\       /  /::\      /  /:/\:\
    |  |:|:\     /  /:/\:\        \__\:\     /  /:/\:\      |  |:|:\      |  |:|:\     /  /:/\:\    /  /:/  \:\
  __|__|:|\:\   /  /:/  \:\   ___ /  /::\   /  /:/~/::\   __|__|:|\:\   __|__|:|\:\   /  /:/~/::\  /__/:/ \__\:|
 /__/::::| \:\ /__/:/ \__\:\ /__/\  /:/\:\ /__/:/ /:/\:\ /__/::::| \:\ /__/::::| \:\ /__/:/ /:/\:\ \  \:\ /  /:/
 \  \:\~~\__\/ \  \:\ /  /:/ \  \:\/:/__\/ \  \:\/:/__\/ \  \:\~~\__\/ \  \:\~~\__\/ \  \:\/:/__\/  \  \:\  /:/
  \  \:\        \  \:\  /:/   \  \::/       \  \::/       \  \:\        \  \:\        \  \::/        \  \:\/:/
   \  \:\        \  \:\/:/     \  \:\        \  \:\        \  \:\        \  \:\        \  \:\         \  \::/
    \  \:\        \  \::/       \  \:\        \  \:\        \  \:\        \  \:\        \  \:\         \__\/
     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/
      ___           ___                       ___
     /  /\         /__/\        ___          /__/\
    /  /::\       |  |::\      /  /\         \  \:\
   /  /:/\:\      |  |:|:\    /  /:/          \  \:\
  /  /:/~/::\   __|__|:|\:\  /__/::\      _____\__\:\
 /__/:/ /:/\:\ /__/::::| \:\ \__\/\:\__  /__/::::::::\
 \  \:\/:/__\/ \  \:\~~\__\/    \  \:\/\ \  \:\~~\~~\/
  \  \::/       \  \:\           \__\::/  \  \:\  ~~~
   \  \:\        \  \:\          /__/:/    \  \:\
    \  \:\        \  \:\         \__\/      \  \:\
     \__\/         \__\/                     \__\/
     _____          ___           ___           ___           ___
    /  /::\        /  /\         /  /\         /  /\         /  /\          ___       ___
   /  /:/\:\      /  /::\       /  /::\       /  /::\       /  /:/_        /  /\     /  /\
  /  /:/  \:\    /  /:/\:\     /  /:/\:\     /  /:/\:\     /  /:/ /\      /  /:/    /  /:/
 /__/:/ \__\:|  /  /:/  \:\   /  /:/~/:/    /  /:/  \:\   /  /:/ /::\    /  /:/    /__/::\
 \  \:\ /  /:/ /__/:/ \__\:\ /__/:/ /:/___ /__/:/ \__\:\ /__/:/ /:/\:\  /  /::\    \__\/\:\__
  \  \:\  /:/  \  \:\ /  /:/ \  \:\/:::::/ \  \:\ /  /:/ \  \:\/:/~/:/ /__/:/\:\      \  \:\/\
   \  \:\/:/    \  \:\  /:/   \  \::/~~~~   \  \:\  /:/   \  \::/ /:/  \__\/  \:\      \__\::/
    \  \::/      \  \:\/:/     \  \:\        \  \:\/:/     \__\/ /:/        \  \:\     /__/:/
     \__\/        \  \::/       \  \:\        \  \::/        /__/:/          \__\/     \__\/
                   \__\/         \__\/         \__\/         \__\/ 
                                      .;codddoc:'.
                                   .lkXWMMMMMMMWN0Oxc'
                                 .oXWMWXOdollox0NWMMWXx;.
                                :0WWWOc.       .'ldkNWWNO:.
                              .lXMWKl.              ,dXWWNk;  .:loxkkOkkxdl:'.
                             .lNMMK;                  'dXMWXd..oXMMMMMMMMMMWN0d;
                            :XMMX;                .':. ;0WMWO,.;oolcccclxOXWWMNk,
                            'OWMNl             .:dk0NWKc..dNWWXc           .l0WMMK:
                            oWMMk.          .:xKWMWWWXOc.  cKMMNl.           .xWMMK;
                           '0MMX: .loo:. .,dKWMMWKOx:'.     ;KMMNo.           .kWMWx.
                   ..;ldx, cNMMO' oXOc..cONMMWXx:...;dkxol:. ;KMMNl            lNMM0'
                'cd0XWWMK, dWMWx..;;.'oKWWWNkc. .lx0WMMMMWW0, ;KMMXc           :NMM0'
             .ckXWMMWXOd:..kWMWo   ,dXMWWKo,    ...';:loxO0XO, :XWMK;          lWMMO.
           .l0WMWNOo;.    .OMXd. ,xNMMW0c.                ..,.  oNMWO. :dl,.  .kWMWd.
          'OWMWXo'        'Ok,.'dNMMWO:.                        .xWMWo..OWWO' :XMMX:
         'OWMWk'          .'..lKWMW0c.            .              ,0MMK; ;0Nx..OMMWx.
         oWMWk.             ;OWWWKl.        .:oxO000Oxl;.         lNMWk. .,..dWMM0,
        .kMMNl            'xNMWNx'        'dKWMMMMMMMWMW0l.       .OMMNc   .oNWMXc ,d;
        .xMMWo           :KWMW0:.        :KMMWMMMMMMMMMMMWO,       lWMMO. .oNMMNl '0WNk,
         cNMMK;        .oNMMNx.         ,KMMMMMMMMMMMMMMMMMO.      ,KMMX: ;KMMNl. 'OWWMXo.
         .dWWWK;      .kWMMKc.'d;       oWMMMMMMMMMMMMMMMMMN:      .xWWWd.'0MXl    .lXMWWx.
          .dNMMNd.   'OWMW0;.;KWd       lNMMMMMMMMMMMMMMMMMX;       cNMM0'.x0:       ;0WMWx.
            :0WMW0l. ,kNWO' ;KMM0'      .OWWMMMMMMMMMWWWWWWx.       ,KMMX; '.         ;KMMNc
             .dXWWWKo'.,:.  '0MMWl       'kNMMMMMMMMMWWWWNd.        .OMMWl            .xMMMx.
               'oKWMMNkc'    lNWM0'       .:kXWMMMMMMWNKd,          .xMMMd.           .xMMMx.
                 .cONMMWXOl,..;okKl          .;coooolc,.         ;o' dWMMk.           :XMMN:
                 ...,o0NWWWW0xc,.'.                            ,kNK, oWMMk.         .lXMMWd.
                .dKd;..,lkXWMWMNKko:'.                       ;kNWM0' dMMMk.       'l0WWWXo.
                ,KWMX:    .;oOXWMMMWNKkdl:'..              .oOKK0x; .xMMMk.  .':oOXWMWXx,
                :NWW0,        .,cdOKNWMMMWNX0kxolc::,'......''....  .kMMMd 'xKNWMMWXkl'
                cNMM0'            .,,:ldk0XNWMMMMMWWWNXXKK0000OOOOc ,KMMNc cNMNKOd:'
                ;XMMK;            ;kkoc,...';codxO00KXXNNWMMMMMWWX: cNMMK, ,l:,.
                .OMMWx.            cXMMXo.   ..,,''''''',;;::::::;..kMMWx.
                 :XMWNx.            :XWWNx. .xXNNXK0d;.            cNMMX:
                  :KWWWKo;..      .  ;OWWW0:.,kKOoc;.             ,0MMWd.
                   'dXWMMWX0kxxxxO0O:..xNWWNx'...                'OWMWO.
                     .cx0XWWMMMMMMWWKc..:0WWWXd'                ,OWMWO,
                        ..,:cllllc:;'.   .oXWMWXd;..          'oXMMWO'
                                           'oKWWMNX0dc,'...,cxXWMWXo.
                                             .:kXWWWMMWNXXXWWMMWXd'
                                                .:cok0XNWWWNKOdc.
                                                     ..',,,'.
*/