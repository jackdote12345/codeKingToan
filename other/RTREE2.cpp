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

vector<pair<int,int>> a[100005];
int fen[200005], lca[100005][log +2], high[100005], in[100005], out[100005], cnt = 0, luu[100005]; 

void dfs(int u, int par)
{
	lca[u][0] = par;
	in[u] = ++ cnt;
	high[u] = high[par] + 1;
	
	for (auto v : a[u])
	if (v.fi != par)
	{	
		dfs(v.fi, u);
		luu[v.se] = v.fi;
	}

	out[u] = ++ cnt;
}

int findlca(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = log; i >= 0; i--) if (high[lca[u][i]] >= high[v]) u = lca[u][i];
	if (u == v) return u;

	for (int i = log; i >= 0; i--) if (lca[u][i]  != lca[v][i])
	{
		u = lca[u][i]; v = lca[v][i];
	} 
	return lca[u][0];
}

void update(int id, int val)
{
	for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}

int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}

void solve() 
{	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].pb({v, i}); a[v].pb({u, i});
	}

	dfs(1, 0);

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n; j++)
	lca[j][i] = lca[lca[j][i-1]][i-1];

	while(m--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int u, v;
			cin >> u >> v;
			int uv = findlca(u, v);
			update(u, 1); update(v, 1); update(uv, -2);
		}
		else
		{
			int u;
			cin >> u;
			cout << u << endl;
			//cout << get(out[luu[u]]) - get(in[luu[u]] - 1) << "\n";
		}
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
