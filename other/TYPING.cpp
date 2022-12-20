#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

void query1(const string &s)
{
	char cur = 0;
	if (s[0] != 'T') cur = s[0];
	int n = (int)s.size();
	int res = 0;
	for (int i = 1; i < n; i++) if (s[i] != 'T')
	{
		if (cur == 0) cur = s[i];
		else if (s[i] != cur)
		{
			res++; cur = s[i];
		}
	}

	cout << res << "\n";
}

void query2(const string &s)
{
	char cur = 0;
	if (s[0] != 'T') cur = s[0];
	int n = (int)s.size();
	int id = 0;
	ll res = 0;
	for (int i = 1; i < n; i++) if (s[i] != 'T')
	{
		if (cur == 0) 
		{
			cur = s[i];
			id = i;
		}
		else if (s[i] != cur)
		{
			//cout << id << " " << i << endl;
			res = (res + 1ll*(n - i)*(id + 1)%MOD)%MOD;
			cur = s[i]; id = i;
		}
		else 
		{
			id = i;
		}
	}

	cout << res << "\n";
}

void solve() 
{
	int ti;
	cin >> ti;
	string s;
	cin >> s;
	if (ti == 0) query1(s); else query2(s);
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooosoooo
    // #endif
   
    freopen("TYPING.inp","r",stdin); freopen("TYPING.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
