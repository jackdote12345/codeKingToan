#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 18
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

vector<pair<int,int>> a[300005];
int lca[300005][log+2], high[300005];
long long dist[300005];

void dfs(int u, int par)
{
	for (auto v : a[u]) if (v.fi != par)
	{
		lca[v.fi][0] = u;
		dist[v.fi] = dist[u] + v.se;
		high[v.fi] = high[u] + 1;
		dfs(v.fi, u);
	}
}

int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);

	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];

	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i] != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	}

	return lca[u][0];
}

long long getdist(int u, int v)
{
	return dist[u] + dist[v] - 2*dist[findlca(u, v)];
}

void solve() 
{
	int n;
	cin >> n >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}

	high[1] = 1;
	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	{
		lca[j][i] = lca[lca[j][i-1]][i-1];
	}

	int q;
	cin >> q;
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		cout << getdist(u ,v) << "\n";
	}
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("distance.inp","r",stdin); freopen("distance.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
