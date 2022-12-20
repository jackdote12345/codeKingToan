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
int st[4000005], lazy[4000005];
void dolazy(int id)
{
	int &add = lazy[id];
	st[id*2] += add; lazy[id*2] += add;
	st[id*2+1] += add; lazy[id*2+1] += add;
	add = 0;
}
void update(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return;
	if (u <= l && r <= v)
	{
		st[id] ++;
		lazy[id] ++;
		return;
	}
	dolazy(id);
	int mid = (l + r)/2;
	update(id*2, l, mid, u, v); update(id*2+1, mid + 1, r, u, v);
	st[id] = min(st[id*2], st[id*2+1]);
}
int getmin(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return oo;
	if (u <= l && r <= v)
	{
		return st[id];
	}
	dolazy(id);
	int mid = (l + r)/2;
	return min(getmin(id*2, l, mid, u, v), getmin(id*2+1,mid + 1, r, u, v));
}
void solve() 
{
	int n;
	vector<int> difval;
	vector<pair<int, pair<int,int>>> ldk;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y, r;
		cin >> x >> y >> r;
		ldk.pb({y, {x , r}});
		//r = r*2;
		difval.pb((-1 - x)*r+1); difval.pb(-x*r);
		difval.pb((-1 - x)*r); difval.pb(-x*r+1);
	}
	sort(ALL(difval));
	difval.resize(unique(ALL(difval)) - difval.begin());
	int cnt = (int)difval.size();
	sort(ALL(ldk));
	int res =0 ;
	for (auto v : ldk)
	{
		int l = lower_bound(ALL(difval), (-1-v.se.fi)*v.se.se+1) - difval.begin() + 1;
		int r = lower_bound(ALL(difval), (-v.se.fi)*v.se.se) - difval.begin() + 1;
		if (getmin(1, 1, cnt, l, r) == 0)
			res++;
		update(1, 1, cnt, l, r);
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
