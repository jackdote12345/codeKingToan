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


int a[500005], b[500005], cs[500005];

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		cs[a[i]] = i - 1;
	}

	bool kt = true;

	for (int i = 1; i <= n; i++) 
	{
		cin >> b[i];
		if ((cs[b[i]] - i + 1 + n)%n != cs[b[1]])
		{
			kt = false;
		}
	}

	if (!kt)
	{
		cout << "NO\n";
		return;
	}

	int val = cs[b[1]];

	if (k == 0 && val == 0)
	{
		cout << "YES\n"; return;
	}

	long long l = k - 1, r = 1ll*k*(n - 1);
	
	long long de = 0, de1 = 0;

	if (l >= val) de = (l - val)/n + 1;
	if (r >= val) de1 = (r - val)/n + 1;

	if (de1 - de > 0)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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
    
    int dem = 0;

    cin >> testcase;
    
    while(testcase--)
    {
    	dem++;
    	cout << "Case #" << dem << ": ";
        solve();
    }
}
