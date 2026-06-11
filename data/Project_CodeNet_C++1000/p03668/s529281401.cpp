/// RESTRICTED AREA
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Os")

/*				As you call 'em, they call you when they need something
				Trees for the blunt, the G's for the front
				I found a way to get peace of mind for years and left the hell alone
				Turn a deaf ear to the cellular phone
				Send me a letter or better, we could see each other in real life
				Just so you could feel me like a steel knife
				At least so you could see the white of they eyes
				Bright with surprise, once they finish spitting lies
				Asssociates, is your boys, your girls, bitches, niggas, homies
				Close, but really don't know me
				Mom, dad, comrade, peeps, brothers, sisters, duns, dunnies
				Some come around when they need some money
				Others make us laugh like the Sunday funnies
				Fam be around whether you paid or bummy
				You could either ignore this advice or take it from me
				Be too nice and people take you for a dummy
				So nowadays he ain't so friendly
				Actually they wouldn’t have made a worthy enemy
				Read the signs: "No feeding the baboon"
				Seein' as how they got ya back bleeding from the stab wounds
				Y'all know the dance, they smile in ya face, y'all know the glance
				Try to put 'em on, they blow the chance
				Never let your so-called mans know your plans
				(How many of us have them?) A show of hands
				(Friends) is a term some people use loosely
				I'm real choosy on what I choose to let crews see
				You telling me; I try to act broke
				Jealousy the number one killer among black folk
				Fellas be under some type of spell like crack smoke
				Ghetto Cinderellas, lead 'em right to your stack, loc
				Just another way a chick'll lead to your end
				I check the dictionary for the meaning of friend
				It said: person, one who likes to socialize with
				Sympathiser, helper, and that's about the size of it
				Most of the time these attributes is one-sided
				To bolster the crime, they're apt to shoot you through your eyelid
				And they can't hide it, going wild like a white bitch				*/

/*				Who knew evil girls had the prettiest face					*/

/*				Me-meet me at The London
				If you find time, we can run one
				Talk about some things we can't undo
				You just send the pin, I can find you
				6'1", on the money, 9'2"
				You just say the word and I'll run through
				Two texts, no reply, that's when I knew
				I knew, I knew, yeah, I knew
				
				Yeah, circumnavigate the globe as the cash grows
				Get a nigga whacked like you get the grass mowed
				I'm talkin' slick when I'm with the Big Slime, nigga
				Could hit your bitch, you could never hit mine, nigga
				In my DM, they electric slide, nigga
				No catfishin', this is not a fish fry, nigga
				Never switch sides on my dog
				Catch a contact, hitch a ride, go to Mars
				Everybody sing
				How could you come up out your face
				And say I ain't the hottest nigga you done ever heard?
				I left a flock of rappers dead and buried
				A verse from me is like eleven birds
				Just did the math, that's like two thousand dollars every word
				I'm on the verge, I'll beat the charge
				I killed some niggas and I walked away from it
				Then I observe, just how you curve
				Then told the nigga that they gotta wait for it
				"I know—I know you in high demand"
				I'm ballin' on a pussy nigga like Juwanna Mann
				I'm drownin' all inside the pussy like I never swam
				Ayy, fuck your IG, I put somethin' on your sonogram
				I'm the man, ayy, ayy										*/

/*				I'm not god, baby / I don't forgive, baby					*/

/*				I'm like "Hey, what's up? Hello"
				Seen yo pretty ass soon as you came in the door
				I just wanna chill, got a sack for us to roll
				Married to the money, introduced her to my stove
				Showed her how to whip it, now she remixin' for low
				She my trap queen, let her hit the bando
				We be countin' up, watch how far them bands go
				We just set a goal, talkin' matchin' Lambos
				At fifity six a gram, five a hundred grams though
				Man, I swear I love her, how she work the damn pole
				Hit the strip club, we be lettin' bands go
				Everybody hatin', we just call them fans, though
				In love with the money, I ain't never lettin' go			*/

/*				We pop out at your party, I'm with the gang
				And it's gon' be a robbery, so tuck ya chain
				I'm a killer girl, I'm sorry, but I cannot change
				We ain't aiming for your body, shots hit you brain
				We come from poverty, man, we ain't have a thing
				It's a lot of animosity, but they won't say my name
				Them killers rock with me, lil' nigga, don't get banged
				'Cause they'll do that job for me while I hop on a plane	*/

/*				I take you to the candy shop								*/

/*				Baby, let me put your panties to the side
				I'ma make you feel alright
				'Cause I'ma give you what you need, yeah					*/

/*				Ooooh ooh, it's me, myself and I
				Solo ride until I die, 'cause I got me for life				*/

/*				So I ball So hard, muh'fuckas wanna find me					*/

/*				Bitch, where you when I was walkin'?
				Now I run the game, got the whole world talkin'				*/
 
/*				Niggas been counting me out
				I'm counting my bullets, I'm loading my clips
				I'm writing down names, I'm making a list					*/

/*				Fuck your friendship, I meant it							*/

/*				The Chanel or Balenciaga, Louis and Vuitton
				She know I got Fendi, Prada when I hit Milan				*/

/*				I ran away, I don't think I'm coming back home				*/ 
 
#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define mp make_pair
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e5+10, maxm=3e3+10, lg=61, mod=998244353, inf=1e18;

ll n;
vector<ll> g[maxn];
ll dfs(ll v=1,ll p=0){
	ll xo=0; for(auto u:g[v])if(u!=p) xo^=(dfs(u,v)+1);
	return xo;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<n;i++){
		ll v,u; cin>>v>>u;
		g[v].pb(u), g[u].pb(v);
	}
	cout<<(dfs(1)==0 ? "Bob":"Alice");
	
	return 0;
}




