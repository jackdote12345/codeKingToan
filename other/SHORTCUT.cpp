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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
typedef pair<long long,int> DATA;
int n, m, to[100005];
long long dist[100005], c[100005], T;
vector<pair<int,int>> a[100005];
vector<int> ed[100005];
void dij(int u)
{
	for (int i = 1; i <= n; i++) dist[i] = oo15;
	dist[u] = 0;
	priority_queue<DATA, vector<DATA>, greater<DATA>> pq;
	pq.push({0, u});
	while(!pq.empty())
	{
		u = pq.top().se; long long len = pq.top().fi; pq.pop();
		if (dist[u] != len) continue;
		//cout << u << endl;
		for (auto v : a[u])
		if (dist[v.fi] > len + v.se)
		{
			dist[v.fi] = len + v.se;
			to[v.fi] = u;
			pq.push({dist[v.fi], v.fi});
		} else if (dist[v.fi] == len + v.se && to[v.fi] > u) to[v.fi] = u;
	}
}
void dfs(int u)
{
	for (auto v : ed[u])
	{
		dfs(v);
		c[u] += c[v];
	}
	//cout << u << " " << c[u] << endl;
}
void solve() 
{
	cin >> n >> m >> T;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].pb({v, w}); a[v].pb({u, w});
	}
	dij(1);
	for (int i = 2; i <= n; i++) ed[to[i]].pb(i);
	dfs(1);
	long long res = 0;
	for (int i = 2; i <= n; i++) if (dist[i] > T) res = max(res, c[i]*(dist[i] - T));
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
