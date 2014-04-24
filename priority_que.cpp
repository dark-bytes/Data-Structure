#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Code for priority queue

class prio_que{
	private:
			vector<int> p;
	public:
		prio_que(int n){
			p.resize(n);
		}
		void insert(int x,int pos){
			p[pos] = x;
		}
		int max(){
			return *(max_element(p.begin(),p.end()));
		}
		int extract_max(){
			int temp = *(max_element(p.begin(),p.end()));
			p.erase(max_element(p.begin(),p.end()));
		}
		void display(){
			for(int i = 0;i < p.size(); i++){
				cout<<p[i]<<"  ";
			}
		}
};
int main()
{
	prio_que que(6);
	int n;
	for(int i = 0;i < 6;i++){
		cin>>n;
		que.insert(n,i);
	}
	
	cout<<"Maximum element is->"<<que.max()<<endl;
	que.extract_max();
	que.display();
}
