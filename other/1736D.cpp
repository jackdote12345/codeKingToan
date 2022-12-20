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

char s[200005];

void solve() 
{
	int n;
	int dem = 0;
	cin >> n;
	for (int i = 1; i <= 2*n; i++)
	{
		cin >> s[i];
		if (s[i] == '1') dem++;
	}

	if (dem%2) 
	{
		cout << "-1\n"; return;
	}

	int w = 1;

	vector<int> ldk;

	for (int i = 1; i <= 2*n; i+=2)
	if (s[i] != s[i + 1])
	{
		if (s[i] - '0' == w) ldk.pb(i); else ldk.pb(i+1);
		w = 1  -w;
	}

	cout << (int)ldk.size() << " "; for (auto v : ldk) cout << v << " "; cout << "\n";
	for (int i = 1; i <= 2*n; i+=2)cout << i << " "; cout << "\n";
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
