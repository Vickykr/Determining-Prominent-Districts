#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define endl '\n'
using namespace std;
const int INF = 1e10L;
int32_t main()
{
	//cout.precision(15);
	//cout.setf(ios::fixed,ios::floatfield);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Goa.txt","r",stdin);
	//freopen("Bihar.txt","r",stdin);
	//freopen("Chattisgarh.txt","r",stdin);
	//freopen("Sikkim.txt","r",stdin);
	//freopen("haryana.txt","r",stdin);
	//freopen("Kerala.txt","r",stdin);
	//freopen("Maharashtra.txt","r",stdin);
	//freopen("manipur.txt","r",stdin);
	//freopen("mizoram.txt","r",stdin);
	//freopen("MP.txt","r",stdin);
	//freopen("Nagaland.txt","r",stdin);
	//freopen("Odisha.txt","r",stdin);
	//freopen("Punjab.txt","r",stdin);
	//freopen("Tamil_nadu.txt","r",stdin);
	//freopen("UP.txt","r",stdin);
	//freopen("Uttarakhand.txt","r",stdin);
	//freopen("WB.txt","r",stdin);
	//freopen("assam.txt","r",stdin);
	//freopen("meghalaya.txt","r",stdin);
	//freopen("tripura.txt","r",stdin);
	//freopen("arunachalpradesh.txt","r",stdin);
	//freopen("Gujrat.txt","r",stdin);
	//freopen("Himachal.txt","r",stdin);
	//freopen("Rajasthan.txt","r",stdin);
	//freopen("telangana.txt","r",stdin);
	//freopen("karnatka.txt","r",stdin);
	freopen("jharkhand.txt","r",stdin);
	freopen("jharkhand_nodes.csv","w",stdout);
	int i,n,m;
	string s,t;
	cin>>n;
	map<string,int> mp;
	map<pair<int,int>,int> mpe;
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=i;
	}
	vector<int> graph[n+1];
	cin>>m;
	cout<<"Start,End"<<endl;
	for(i=0;i<m;i++)
	{
		cin>>s>>t;
		cout<<s<<","<<t<<endl;
	}
}

