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

int dd[300005];
void solve() 
{
	int n, k, t, r;
	cin >> n >> k >> t >> r;
	cout << k << endl;
	// for (int i = 1; i <= k; i++)
	// {
	// 	int x;
	// 	cin >> x;
	// 	dd[x] = true;
	// }
	// deque<int> ldk;
	// int dem = 0;
	// for (int i = 1; i < r; i++) if (!dd[i]) ldk.pb(i); else dem++; 
	// vector<int> res;
	// for (int i = r; i <= n; i++)
	// {
	// 	if (dd[i]) dem++; else ldk.pb(i);
	// 	if (i - r > 0 && dd[i - r]) dem--; else if (ldk.front() == i - r) ldk.pop_front();
	// 	while(dem < t)
	// 	{
	// 		dd[ldk.back()] = true; res.pb(ldk.back()); dem++; ldk.pop_back();
	// 	} 
	// }
	// cout << (int)res.size() << "\n";
	// for (auto v : res) cout << v << " ";

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
