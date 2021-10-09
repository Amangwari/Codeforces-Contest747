#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
//#define mod 998244353
#define mod 1000000007
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,pre[N<<1],cnt[N<<1];
vector<int>vc[N<<1];
void init(){
	for(int i=1;i<=n*2;i++){
		pre[i]=i;
		if(i>n)cnt[i]=1;
		else cnt[i]=0;
	}
}
int Find(int x){
	return pre[x]==x?x:pre[x]=Find(pre[x]);
}
void f(int u,int v){
	int fx=Find(u),fy=Find(v);
	if(fx!=fy){
		pre[fx]=fy;
		cnt[fy]+=cnt[fx];
		cnt[fx]=0;
	}
}
void solve(){
	int u,v;
	string s;
	cin>>n>>m;
	init();
	while(m--){
		cin>>u>>v>>s;
		if(s[0]=='i'){
			f(u,v+n);
			f(u+n,v);
		}
		else{
			f(u,v);
			f(u+n,v+n);
		}
	}
	for(int i=1;i<=n;i++){
		if(Find(i)==Find(i+n)){
			cout<<-1<<'\n';
			return ;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(cnt[i],cnt[i+n]);
	}
	cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    //cout<<fixed<<setprecision(10);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
