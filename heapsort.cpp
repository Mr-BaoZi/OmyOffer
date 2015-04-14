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

void siftdown(int i){
	int t,flag=0;
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

void create(){
	for(int i=n/2;i>=1;i--){
		siftdown(i);
	}
}
int deleteMax(){
	int t;
	t = h[1];
	h[1]=h[n];
	n--;
	siftdown(1);
	return t;
}
int main() {
	// your code goes here
	int i,num;
	cin>>num;
	for(i=1;i<=num;i++){
		cin>>h[i];
	}
	n=num;
	
	create();
	for(i=1;i<=num;i++){
		cout<<h[i]<<"~~~~";
	}
	
	for(i=1;i<=num;i++){
	
		cout<<deleteMax()<<endl;
	}
	
	return 0;
}