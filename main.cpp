//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf 1<<30
#define eps 0.000000001
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // let's fuck the bfs and dfs
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n][m];
        f(i,n)
        {
            f(j,m)
            {
                cin>>a[i][j];
            }
        }
        vector<int> adj[n*m+1];
        vector<int> val(n*m+1,0);
        vector<int> parent(n*m+1,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                val[i*m+j+1]=a[i][j];
                if(i-1>=0)
                {
                    adj[i*m+j+1].pb((i-1)*m+j+1);
                }
                if(i+1<n)
                {
                    adj[i*m+j+1].pb((i+1)*m+j+1);
                }
                if(j-1>=0)
                {
                    adj[i*m+j+1].pb(i*m+j);
                }
                if(j+1<m)
                {
                    adj[i*m+j+1].pb(i*m+j+2);
                }
            }
        }
        long long sum=0;
        vector<int>vis(n*m+1,0);
        vector<int>ids;
        for(int i=1;i<=n*m;i++)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
            p.push(mp(val[i],i));
            ids.pb(p.top().ss);
            vis[p.top().ss]=1;
            int maxi=0;
            int temp;
            do
            {
                temp=p.top().ss;
                p.pop();
                for(int i:adj[temp])
                {
                    if(vis[i]==0)
                    {
                        parent[i]=temp;
                        vis[i]=1;
                        ids.pb(i);
                        p.push(mp(val[i],i));
                    }
                }
            }
            while(adj[temp].size()==4);
            int nik=temp;
            while(parent[nik]!=-1)
            {
                maxi=max(maxi,val[nik]);
                nik=parent[nik];
            }
            if(maxi>val[i])
            {
                sum=sum+maxi-val[i];
            }
            while(ids.size()>0)
            {
                vis[ids.back()]=0;
                parent[ids.back()]=-1;
                ids.pop_back();
            }
        }
        cout<<sum<<endl;
    }
}
