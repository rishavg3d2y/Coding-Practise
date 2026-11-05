#include <iostream>
#include <algorithm>
#include <array>
#include <memory>
#include <vector>
using namespace std;
int main() {

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int v= m*n;
        vector<int> is_visited;
        for(int i=0; i<m*n ; i++){
          
                is_visited.push_back(0);
    }
    queue<int> q;
    int ct=0;
    
    int i0=0;
    int j0=0;
    while(i0<m && j0<n){
        if (grid[i0][j0]=='1' && is_visited[i0*n+j0]==0){
            q.push(i0*n+j0);
            is_visited[n*i0+j0]=1;
            
            ct++;
        }

        while(!q.empty()){

        int x= q.front();
        q.pop();
        int i= x/n;
        int j= x%n;
        array<array<int,2>,4> nbrs= {{{i,j-1},{i-1,j},{i+1,j},{i,j+1}}};
        for (array<int,2> y: nbrs){
            if (y[0]<m && y[0]>=0 && y[1]<n && y[1]>=0 && is_visited[n*y[0]+y[1]]==0 && grid[y[0]][y[1]]=='1'){
                q.push(y[0]*n+y[1]);
                is_visited[n*y[0]+y[1]]=1;
            }
        }
       
    }
    if(j0<n-1){
        j0=j0+1;
    }
    else{
        j0=0;
        i0=i0+1;
    }
}
 return ct;
    }
};
}
