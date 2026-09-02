#include <iostream>
#include <vector>
using namespace std;
void dfs(int row,int col,vector<vector<char>>&a){
if(row<0 || row>=a.size()|| col<0 ||col>=a[0].size()){
return;
}
if(a[row][col]=='.'){
a[row][col]='#';}
else{
    return;
}
dfs(row,col-1,a);
dfs(row-1,col,a);
dfs(row,col+1,a);
dfs(row+1,col,a);
}
int main() {
int n,m;
cin>>n>>m;
vector<vector<char>> a(n,vector<char>(m));
int t=0;
for(int row=0;row<n;row++){
    for(int col=0;col<m;col++){
cin>>a[row][col];
    }
}

for(int row=0;row<n;row++){
    for(int col=0;col<m;col++){
        if(a[row][col]=='.'){
            t++;
            dfs(row,col,a);
        }
    }}
    cout<<t;
    return 0;
}
