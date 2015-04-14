#include <iostream>
using namespace std;

int h[101];
int n;

void swap(int x,int y){
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
}

//向下调整
void siftdown(int i){
	int t,flag=0;
	//（子树）根节点与最小孩子交换
	while( i*2<=n && flag==0){
		if(h[i] > h[i*2]){
			t = i*2;
		}
		else{
			t = i;
		}
		if (i*2+1 <= n){
			if(h[t] > h[i*2+1]){
				t = i*2+1;
			}
		}
		if(t!=i){
			swap(t,i);
			i=t;
		}
		else{
			flag = 1;
		}
	}
}

//创建（最小）堆
void create(){
	for(int i=n/2;i>=1;i--){
		siftdown(i);
	}
}
//删除堆顶节点
int deleteMax(){
	int t;
	t = h[1];
	h[1]=h[n];//尾节点放到堆顶 重新向下调整
	n--;
	siftdown(1);
	return t;
}
int main() {
	
	int i,num;
	cin>>num;
	for(i=1;i<=num;i++){
		cin>>h[i];
	}
	n=num;
	
	create();
	for(i=1;i<=num;i++){
		cout<<h[i]<<"---";
	}
	
	for(i=1;i<=num;i++){
	
		cout<<deleteMax()<<endl;
	}
	
	return 0;
}