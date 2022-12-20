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


void solve() 
{
	vector<pair<int,int>> ldk;
	string s;
	cin >> s;
	cout << abs(s[0] - s.back()) << " ";
	for (int i = 0; i < (int)s.size(); i++)
	if ((s[0] - s[i])*(s.back() - s[i]) <= 0)
	{
		if (s[0]  > s.back())
		ldk.pb({-1*s[i], i + 1});
		else ldk.pb({s[i], i + 1});
	}
	sort(ALL(ldk));
	cout << (int)ldk.size() << "\n";
	for (auto v : ldk) cout << v.se << " ";
	cout << "\n";
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
