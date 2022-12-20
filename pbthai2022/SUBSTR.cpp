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

int dd[50], nxt[100005][40];

void solve() 
{
	string s;
	cin >> s;
	int n = (int)s.size();

	for (int i = 0; i < 26; i++) dd[i] = -1;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			nxt[i][j] = dd[j];
		}
		dd[s[i] - 'a'] = i;
	}


	int q;
	cin >> q;
	while(q--)
	{
		string st; cin >> st; int m = (int)st.size();
			
		int id = -1;

		if (dd[st[0] - 'a'] == -1)
		{
			cout << "no\n"; continue;
		}
		else id = dd[st[0] - 'a'];

		bool kt = true;

		for (int i = 1; i <  m; i++)
		if (nxt[id][st[i] - 'a'] == -1)
		{
			kt = false; break;
		}
		else id = nxt[id][st[i] - 'a'];

		
		if (kt) cout << "yes\n"; else cout << "no\n";
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
