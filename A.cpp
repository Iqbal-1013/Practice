#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int arr[200011];
int tree[200111];
int n;
priority_queue<int>pq,pq1;

void upd(int id){
    while(id<=n){
        tree[id]++;
        id += (id&-id);
    }
}
int query(int id){
    int sum = 0;
    while(id){
        sum += tree[id];
        id -= (id&-id);
    }
    return sum;
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int ans = 2000111;
    bool flag = 0;
    for(int i=1;i<=n;i++){
        int sum = query(arr[i]-1);
        //cout<<i <<" "<<sum<<endl;
        if( sum != i-1 )flag=1;
        if(sum==i-2){
            ans = min(ans,pq.top());
           // cout<<pq.top()<<endl;
        }
        if(sum==i-1 && pq1.size()){
            ans = min( ans , pq1.top()*-1 );
        }
        upd(arr[i]);
        pq.push(arr[i]);
        pq1.push(-arr[i]);
    }
    if(flag){
        cout<<ans<<endl;
    }
    else{
        cout<<"1"<<endl;
    }
    return 0;
}
