#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[30],s[30];
int n,k=2,minn=0x7ffff;
void search(int,int);
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) //����ÿ��ʱ��
        scanf("%d",&a[i]);
    search(1,0);//�����һ��ʱ�䣬���ڻ��ѵ�ʱ����0��
    cout<<minn;
    return 0;
}
void search(int x,int y) {
    if(y>=minn)return;//��֦ �Ѿ�����С�Ĵ��˾Ͳ����ٷ��ˣ��������ַ���
    if(x>n) { //�����˽����ж�
        if(y<minn)minn=y;
        return;
    }
    for(int i=1; i<=k; i++) {
        if(s[i]+a[x]<=minn) { //��֦
            s[i]+=a[x];
            search(x+1,max(y,s[i]));
            s[i]-=a[x];//����
        }
    }
    return;
}
