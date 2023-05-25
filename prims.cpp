/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void Prims(vector<pair<int,int>>adj[],int n){
    
    //pq -> {wt,{node,parent}};
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>vis(n,0);
    pq.push({0,{0,-1}});
    int sum=0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        
        if(vis[node] == 1){
            continue;
        }
        
        vis[node] = 1;
        sum += wt;
        cout<<node<<" "<<parent<<" wt :"<<wt<<endl;
        for(auto it2:adj[node]){
            int awt = it2.second;
            int anode = it2.first;
            
            if(!vis[anode]){
                pq.push({awt,{anode,node}});
            }
        }
    }
    
    cout<<"sum "<<sum;
    
}


int main()
{
    int n;
    cout<<"enter n ";
    cin>>n;
    int m;
    cout<<"enter edges : ";
    cin>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back(make_pair(y,wt));
        adj[y].push_back(make_pair(x,wt));
    }
    Prims(adj,n);
    
    
    
    return 0;
}


