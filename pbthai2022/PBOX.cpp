#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve() 
{
	string s;
	cin >> s;

	int n = (int)s.size();
	long long res = 0;
	int dem = 0;
	int vt = 0;
	int st = 0;

	for (int i = 1; i < n; i++)
	if (s[i] != s[i-1])
	{
		if (s[i-1] == '#' && st != 0)
		{
			int sl = i - st;
			res += 1ll*(sl - 1)*sl/2;
			if (vt > st)
			{
				res += 1ll*sl*(vt - st);
			}
			vt = max(vt, st);
			for (int j = vt; j <= vt + 2*sl - 2; j += 2)
			{
				res += j - dem; dem++;
			}
			vt = vt + 2*sl;
		} else if (s[i-1] == '#' && st == 0) dem = i;
		st = i;
	}	

	if (s[n-1] == '#' && st != 0)
	{
		cout << "-1"; return;
	}

	vt -= 2;

	if (vt >= n - 1)
	{
		cout << -1; return;
	}

	cout << res;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
