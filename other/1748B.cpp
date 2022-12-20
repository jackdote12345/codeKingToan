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

int dem[100];
bool dd[100];

void solve() 
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll res = 0;

	for (int i = 0; i < n; i++)
	{
		int diff = 0, mx = 0;
		for (int j = 0; j <= 9; j++)
		{
			dd[j]  = false; dem[j] = 0;
		}
		for (int j = i; j < n; j++)
		{
			dem[s[j] - '0']++; if (!dd[s[j] - '0'])
			{
				diff++; dd[s[j] - '0'] = true;
			}
			mx = max(mx, dem[s[j] - '0']);
			if (mx <= diff) 
			{
				res++;
			}
			if (mx >= 11) break;
		}
	}
	cout << res << "\n";
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
