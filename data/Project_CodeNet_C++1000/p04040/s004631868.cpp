#include <iostream>
#include <algorithm>
#include <vector>
#define repeat(n) for (size_t i = 0; i < n; i++)
#define ull unsigned long long
#define vll vector<ull>
constexpr ull MOD = 10e8+7;

using namespace std;

ull mod_saberi(ull x, ull y)
{
	return (x % MOD + y % MOD) % MOD;
}
ull mod_pomnozi(ull x, ull y)
{
	return ((x % MOD) * (y % MOD)) % MOD;
}
bool je_paran(ull broj) { return !(broj & 1); }
ull brzo_stepenuj(ull osnova, ull exponent)
{
	if (exponent == 0)
		return 1;
	if (je_paran(exponent))
	{
		ull exp_pola = brzo_stepenuj(osnova, exponent / 2);
		return mod_pomnozi(exp_pola, exp_pola);
	}
	else
	{
		ull ostatak = osnova;
		ull exp_pola = brzo_stepenuj(osnova, (exponent - 1) / 2);
		return mod_pomnozi(ostatak, mod_pomnozi(exp_pola, exp_pola));
	}
}
ull n_choose_k(ull n_faktorijel, ull k_faktorijel, ull nk_faktorijel)
{
	return mod_pomnozi(n_faktorijel, brzo_stepenuj(mod_pomnozi(k_faktorijel, nk_faktorijel), MOD - 2));
}

vll broj_nacina_do_polja(ull polja_horizontalno, ull polja_vertikalno, int broj_polja)
{
	vll broj_nacina = vll(broj_polja);
	ull n_faktorijel = 1, k_faktorijel = 1, nk_faktorijel = 1;
	for (ull i = 1; i <= polja_horizontalno + polja_vertikalno; i++)
	{
		n_faktorijel = mod_pomnozi(n_faktorijel, i);
		if (i == (polja_vertikalno))
			nk_faktorijel = n_faktorijel;
		if (i == polja_horizontalno)
			k_faktorijel = n_faktorijel;
	}

	for (size_t i = 1; i <= broj_polja; i++)
	{
		broj_nacina[i - 1] = n_choose_k(n_faktorijel, k_faktorijel, nk_faktorijel);
		n_faktorijel = mod_pomnozi(n_faktorijel, polja_horizontalno + polja_vertikalno + i);
		nk_faktorijel = mod_pomnozi(nk_faktorijel, polja_vertikalno + i);
	}
	return broj_nacina;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	vll broj_nacina_desno = broj_nacina_do_polja(W - B - 1, A, H - A);
	reverse(broj_nacina_desno.begin(), broj_nacina_desno.end());
	vll broj_nacina_levo = broj_nacina_do_polja(B - 1, 0, H - A);
	ull ukupno_nacina = 0;
	for (size_t i = 0; i < broj_nacina_levo.size(); i++)
	{
		ukupno_nacina = mod_saberi(ukupno_nacina, mod_pomnozi(broj_nacina_levo[i], broj_nacina_desno[i]));
	}
	cout << ukupno_nacina << "\n";
	return 0;
}