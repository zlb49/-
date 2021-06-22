#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
    int x;
    int y;
};
bool compare1(node p1,node p2){
    return p1.x < p2.x;
}
bool compare2(node p1,node p2){
    return p1.y < p2.y;
}
//计算两点之间的距离
double dis(node p1,node p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));    
}
//求最近点对 
double partition(node p[],int left,int right)
{
    //2<=n<=3则直接求解 
    if(right - left == 1){
        return dis(p[left],p[right]);
    }
    if(right - left == 2){
        double d1 = dis(p[left],p[left+1]);
        double d2 = dis(p[left],p[right]);
        double d3 = dis(p[left+1],p[right]);
        d2 = min(d1,d2);
        d3 = min(d2,d3);
        return d3;
    }
    //n>3时，分治法求解
    int m = (left + right)/2;
    double d1 = partition(p,left,m);
    double d2 = partition(p,m+1,right);
    double d = min(d1,d2);
    int l=left,r=right;
    //筛选中间可能距离最小的坐标
    while(p[l].x<p[m].x-d && l<=right){
        l++;
    }
    while(p[r].x>p[m].x+d && l<=left){
        r--;
    }
    double d3;
    //将筛选后的点以y坐标从小到大排序
    sort(p+l,p+r+1,compare2);
    for(int i=l;i<r;i++){
        for(int j=i+1;j<r;j++){
            //筛选中间可能距离最小的坐标
            if(p[j].y-p[i].y > d){
                break;
            }
            else{
                d3 = dis(p[i],p[j]);
                if(d3 < d){
                    d = d3;
                } 
            }
        }
    }
}
int main(){
    node p[100]; 
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i].x >> p[i].y;
    }
    //对所有的点按照x坐标从小到大排序
    sort(p,p+n,compare1);
    double d = partition(p,1,n);
    cout << d << endl;
    return 0;
}

