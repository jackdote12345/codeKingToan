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
const long long MOD2 = 1e9 + 9;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool visit[1005], dd[1005];
int ans[1005], g[1005], grandy[1005];
vector<int> a[1005];

long long power(long long x, long long y, long long z)
{
	if (y == 0) return 1;
	long long xx = power(x, y/2, z);
	if (y%2) return xx*xx%z*x%z; else return xx*xx%z;
}

void dfs(int u)
{
	visit[u] = true; grandy[u] = 0;
	vector<int> ldk;
	for (auto v : a[u])
	{
		if (visit[v] != true) dfs(v);
		ldk.pb(grandy[v]);
	}
	for (auto v : ldk)
	{
		dd[v] = true;
		while(dd[grandy[u]]) grandy[u]++;
	}
	for (auto v : ldk) dd[v] = false;
	ans[grandy[u]] ^= g[u];
}

int cal(long long w)
{
	if (w == 1) return 0;
	int res = 0;
	for (int i = 2; i <= w && i <= 100000; i++)
	if (w%i == 0)
	{	
		while(w%i == 0)
		{
			res++; w /= i;
		}
	}

	if (w == 1)
	{
		return res - 1;
	}

	for (int i = 1; i <= 100; i++)
	{
		long long e = rng()%(w - 1) + 1;

		if (power(e, w - 1, w) != 1) return res + 1;
	}

	return res;
}

void solve() 
{
	int n, m;
	cin >> n >> m;

	ans[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		long long w;
		cin >> w;
		g[i] = cal(w);
		a[i].clear();
		visit[i] = false;
		ans[i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
	}
	for (int i = 1; i <= n; i++) if (visit[i] == false) dfs(i);

	for (int i = 0; i <= n; i++) if (ans[i]) 
	{
		cout << "1\n";
		return;
	}
	cout << "0\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
