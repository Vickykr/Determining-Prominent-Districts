#include<bits/stdc++.h>
#define int long long int
#define pb push_back
#define endl '\n'
using namespace std;
const int INF = 1e10L;
void all_paths(vector<int> path[],vector<int> &v,int node,int beg,vector<vector<int>>&ans)// Bactracking all paths using possible parents;
{
	if(node==beg)//reaching the beginning
	{
		ans.pb(v);
		return ;
	}
	for(auto x:path[node])//Taking one of  the path
	{
		v.pb(x);
		all_paths(path,v,x,beg,ans);
		v.pop_back();
	}
}
void store_par_bfs(int beg,vector<int> path[],vector<int> &dis,vector<int> graph[])// finding parents of each node which will contribute to shortest path
{
	dis[beg]=0;//beginning is at distance 0
	queue<int> q;
	q.push(beg);
	while(!q.empty())
	{
		int par=q.front();
		q.pop();
		for(auto child:graph[par])
		{
			if(dis[child]>dis[par]+1)//if shorter path is available
			{
				q.push(child);
				dis[child]=dis[par]+1;
				path[child].clear();
				path[child].pb(par);
			}
			else if(dis[child]==dis[par]+1)//if multiple path is available
			{
				path[child].pb(par);
			}
		}
	}
}
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
	//freopen("Haryana.txt","r",stdin);
	//freopen("Kerala.txt","r",stdin);
	//freopen("Maharashtra.txt","r",stdin);
	//freopen("Manipur.txt","r",stdin);
	//freopen("Mizoram.txt","r",stdin);
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
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("Andhra_Pradesh.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int i,j,k,n,m;//n->number of districts
	string s,t;
	cin>>n;
	double BC[n+1]={0};//Betweenss centrality of each districts
	map<string,int> mp;
	map<pair<int,int>,int> mpe;
	for(i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=i;
	}
	vector<int> graph[n+1];
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>s>>t;
		if(mpe[{mp[s],mp[t]}])continue;//checking already provided edges
		graph[mp[s]].pb(mp[t]);
		graph[mp[t]].pb(mp[s]);
		mpe[{mp[s],mp[t]}]=1;
		mpe[{mp[t],mp[s]}]=1;
	}
	int nosp[n+1]={0},tnsp=0;//nosp-> Number of shortest path, tnsp-> total number of shortest path
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			memset(nosp,0,sizeof(nosp));
			vector<int>dis(n+1,INF);
			vector<int> path[n+1];//stores possible parents
			vector<int> v;
			vector<vector<int>> ans;
			tnsp=0;
			store_par_bfs(i,path,dis,graph);
			all_paths(path,v,j,i,ans);
			for(k=0;k<ans.size();k++)
			{
				for(auto x:ans[k])
				{
					nosp[x]++;
				}
			}
			tnsp=ans.size();
			if(tnsp==0)
			continue;
			for(k=0;k<n;k++)//Calculating contribution in each pair of nodes
			{
				if(k==i or k==j)continue;
				BC[k]+=(double)((double)nosp[k]/tnsp);
			}
		}
	}
	
	for(i=0;i<n;i++)
	cout<<BC[i]<<" ";
	cout<<endl;
}

