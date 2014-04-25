#include <iostream>
#include <vector>
using namespace std;


class heap{
	private:
		vector<int> p;
	public:
		heap(int n){
			p.resize(n);
		}
		void insert(int x,int pos){
			p[pos] = x;
		}
		void max_heapify(int i){
			while( (2*i + 1 < p.size() ) && ( (p[2*i + 1] > p[i]) || (p[2*i + 2] > p[i]) )){
				if( (2*i + 2 >= p.size()) || (p[2*i + 1] > p[2*i + 2]) ){
					swap( p[i],p[2*i + 1] );
					i = 2*i + 1;
				}
				else{
					swap( p[i],p[2*i + 2] );
					i = 2*i + 2;
				}
			}
		}
		void build_heap(){
			cout<<endl<<"BUILD_HEAP->"<<endl;
			for(int i = (p.size())/2 + 1;i >= 0; i--){
				
				max_heapify(i);
			}
		}
		
		void heap_sort(){
			int i = 0;
			for(int j = p.size() - 1;j >= 0;j--){
				int temp = p[i];
				swap( p[i] , p[j] );
				p.pop_back();
				max_heapify(0);
				cout<<temp<<"  ";
			}
		}
		int swap(int& p, int& q){
			int temp = p;
				p = q;
 				q = temp;
		}
		void display(){
			for(int i = 0;i < p.size(); i++){
				cout<<p[i]<<"  ";
			}
			cout<<endl;
		}
};

int main(){
	heap h(10);
	int n;
	for(int i = 0;i < 10;i++){
		cin>>n;
		h.insert(n,i);
	}
	h.build_heap();
	h.display();
	h.heap_sort();
	return 0;
}
