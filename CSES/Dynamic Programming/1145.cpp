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

int lim, fen[200005], a[200005];
void update(int id, int val)
{
	for (; id <= lim; id += (id&(-id))) fen[id] = max(fen[id], val);
}
int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res = max(res, fen[id]);
	return res;
}
void solve() 
{
	int n;
	vector<int> diff;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		diff.pb(a[i]);
	}
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	lim = (int)diff.size() + 1;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diff), a[i]) - diff.begin() + 1;
		int val = get(a[i] - 1) + 1;
		res = max(res, val);
		update(a[i], val);
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
