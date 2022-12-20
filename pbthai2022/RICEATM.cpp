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


pair<int,int> a[100005];
long long dp[100005];
int trace[100005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
	}

	dp[1] = a[1].fi;
	trace[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i-1] + a[i].fi; trace[i] = 1;
		if (dp[i - 2] + a[i-1].se < dp[i])
		{
			dp[i] = dp[i-2] + a[i-1].se;
			trace[i] = 2;
		}
	}

	cout << dp[n] << "\n";

	vector<int> ldk;
	while(n)
	{
		if (trace[n] == 1)
		{
			ldk.pb(1);
			n--;
		}
		else
		{
			ldk.pb(0); ldk.pb(2);
			n -= 2;
		}
	}
	reverse(ALL(ldk)); for (auto v : ldk) cout << v << " ";
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
