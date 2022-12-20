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

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:

    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] = max(fen[id], val);
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res = max(res, fen[id]);
		return res;
	}
};

int p[100005], cost[100005];


void solve() 
{
	vector<int> ldk, dk;
	int n, c, d;
	cin >> n >> c >> d;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> cost[i];
		char cac;
		cin >> cac;
		if (cac == 'C') ldk.pb(i); else dk.pb(i); 
	}

	fenwicktree adu; adu.reset(c);

	int ww = 0;
	
	for (auto v : ldk) if (cost[v] <= c)
	{
		int wu = adu.get(c - cost[v]);
		if (wu > 0)
		{
			ww = max(ww, wu + p[v]);
		} 
		adu.update(cost[v], p[v]);
	}
	int hihi = adu.get(c);

	adu.reset(d);

	for (auto v : dk) if (cost[v] <= d)
	{
		int wu = adu.get(d - cost[v]);
		if (wu > 0)
		{
			ww = max(ww, wu + p[v]);
		}
		adu.update(cost[v], p[v]);
	}

	int hehe = adu.get(d);

	if (hihi && hehe) ww = max(ww, hehe + hihi);

	cout << ww;
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
