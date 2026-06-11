/*
    Valkyrie
                                                //
                                              ,//
                                  ___   /|   |//
                              `__/\_ --(/|___/-/
                           \|\_-\___ __-_`- /-/ \.
                          |\_-___,-\_____--/_)' ) \
                           \ -_ /     __ \( `( __`\|
                           `\__|      |\)\ ) /(/|
   ,._____.,            ',--//-|      \  |  '   /
  /     __. \,          / /,---|       \       /
 / /    _. \  \        `/`_/ _,'        |     |
|  | ( (  \   |      ,/\'__/'/          |     |
|  \  \`--, `_/_------______/           \(   )/
| | \  \_. \,                            \___/\
| |  \_   \  \                                 \
\ \    \_ \   \   /                             \
 \ \  \._  \__ \_|       |                       \
  \ \___  \      \       |                        \
   \__ \__ \  \_ |       \                         |
   |  \_____ \  ____      |                        |
   | \  \__ ---' .__\     |        |               |
   \  \__ ---   /   )     |        \              /
    \   \____/ / ()(      \          `---_       /|
     \__________/(,--__    \_________.    |    ./ |
       |     \ \  `---_\--,           \   \_,./   |
       |      \  \_ ` \    /`---_______-\   \\    /
        \      \.___,`|   /              \   \\   \
         \     |  \_ \|   \              (   |:    |
          \    \      \    |             /  / |    ;
           \    \      \    \          ( `_'   \  |
            \.   \      \.   \          `__/   |  |
              \   \       \.  \                |  |
               \   \        \  \               (  )
                \   |        \  |              |  |
                 |  \         \ \              I  `
                 ( __;        ( _;            ('-_';
                 |___\        \___:            \___:



                 ,,ggddY888Ybbgg,,
          ,agd8""'   .d8888888888bga,
       ,gdP""'     .d88888888888888888g,
     ,dP"        ,d888888888888888888888b,
   ,dP"         ,8888888888888888888888888b,
  ,8"          ,8888888P"""88888888888888888,
 ,8'           I888888I    )88888888888888888,
,8'            `8888888booo8888888888888888888,
d'              `88888888888888888888888888888b
8                `"8888888888888888888888888888
8                  `"88888888888888888888888888
8                      `"8888888888888888888888
Y,                        `8888888888888888888P
`8,                         `88888888888888888'
 `8,              .oo.       `888888888888888'
  `8a             8888        88888888888888'
   `Yba           `""'       ,888888888888P'
     "Yba                   ,88888888888'
       `"Yba,             ,8888888888P"'
          `"Y8baa,      ,d88888888P"'
               ``""YYba8888P888"'     $/              
           __                        O$               
       _.-"  )                        $'              
    .-"`. .-":        o      ___     ($o              
 .-".-  .'   ;      ,st+.  .' , \    ($               
:_..-+""    :       T   "^T==^;\;;-._ $\              
   """"-,   ;       '    /  `-:-// / )$/              
        :   ;           /   /  :/ / /dP               
        :   :          /   :    )^-:_.l               
        ;    ;        /    ;    `.___, \           .-,
       :     :       :  /  ;.q$$$$$$b   \$$$p,    /  ;
       ;   :  ;      ; :   :$$$$$$$$$b   T$$$$b .'  / 
       ;   ;  :      ;   _.:$$$$$$$$$$    T$$P^"   /l 
       ;.__L_.:   .q$;  :$$$$$$$$$$$$$;_   TP .-" / ; 
       :$$$$$$;.q$$$$$  $$$$$$$$$$$$$$$$b  / /  .' /  
        $$$$$$$$$$$$$;  $$$$$$$$P^" "^Tb$b/   .'  :   
        :$$$$$$$$$$$$;  $$$$P^jp,      `$$_.+'    ;   
        $$$$$$$$$$$$$;  :$$$.d$$;`- _.-d$$ /     :    
        '^T$$$$$P^^"/   :$$$$$$P      d$$;/      ;    
                   :    $$$$$$P"-. .--$$P/      :     
                   ;    $$$$P'( ,    d$$:b     .$     
                   :    :$$P .-dP-'  $^'$$bqqpd$$     
                    `.   "" ' s")  .'  d$$$$$$$$'     
                      \           /;  :$$$$$$$P'      
                    _  "-, ;       '.  T$$$$P'        
                   / "-.'  :    .--.___.`^^'          
                  /      . :  .'                      
                  ),sss.  \  :  bug                   
                 : TP""Tb. ; ;                        
                 ;  Tb  dP   :                        
                 :   TbdP    ;                        
                  \   $P    /                         
                   `-.___.-'
*/
#include <bits/stdc++.h>
#define sqr(x) (x * x)
#define cub(x) sqr (x) * (x) 
#define all(x) x.begin(), x.end()
#define fp pop_front
#define bp pop_back
#define pf push_front
#define pb push_back
#define mp make_pair
#define sz size()
#define se second
#define fi first
using namespace std;
#define _ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef double dd;
typedef string st;
typedef char ch;
typedef unsigned long long ull;
typedef bool bl;
typedef long double ld;
typedef int I;
const ld pi = 3.14159265358979323846;
const ll mod = 1e9 + 7;
const ll prost = 37;
const ll N = 5e5 + 500;
const ll INF = 1e18 + 1;
ll w, h, n, a[N];
map <pair <ll, ll>, ll> lol;
bl check (int x, int y) {
    if (x > 1 && x < w && y > 1 && y < h) 
        return true;
    return false;
}
int main () { _
	cin >> w >> h >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		lol[mp(x, y)]++;
		lol[mp(x + 1, y + 1)]++;
		lol[mp(x + 1, y)]++;
		lol[mp(x, y + 1)]++;
	    lol[mp(x - 1, y - 1)]++;
		lol[mp(x - 1, y)]++;
		lol[mp(x, y - 1)]++;
		lol[mp(x + 1, y - 1)]++;
		lol[mp(x - 1, y + 1)]++;
	}
	a[0] = (w - 2) *  (h - 2);
	for (auto kek : lol) 
		if (check(kek.fi.fi, kek.fi.se)) {
			a[0]--;
			a[kek.se]++;
		}
	for (int i = 0; i <= 9; ++i) 
		cout << a[i] << endl;
	return 0;
}