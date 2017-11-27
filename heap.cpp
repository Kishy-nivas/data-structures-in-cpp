#include<bits/stdc++.h>
using namespace std ;

vector<int> arr ;

void add_to_heap(int ele)
{

	int child , parent , last ;

	if(arr.size() == 0)
	{
		arr.push_back(ele) ;
		return ;
	}


	arr.push_back(ele) ;
	child = arr.size() - 1 ;
	parent = (child-1)/2 ;

	do {
		if(arr[parent] > arr[child])
		{
			swap(arr[parent] , arr[child] )	 ;
		}
		child = parent ;

		parent = (child-1) ;

		if(parent < 0 )
			break ;
		parent /= 2 ;

	}	while(parent >= 0);
}

void remove_from_heap()
{


	int last_index = arr.size() - 1 ;
	int parent , left_child , right_child , real_child;

	swap(arr[0]  ,arr[last_index]) ;
	arr.pop_back() ;
	last_index = arr.size() - 1;
	parent = 0 ;

	do{

	right_child = (2*(parent) + 2 ) ;
	left_child = (2*(parent) + 1) ;

	if( right_child <= last_index )
	{
		//both childs present
		//get min in left and right child
		if( arr[right_child] < arr[left_child] )
		{
			//right_child is more
			if(arr[parent] > arr[right_child])
			{
				swap(arr[parent]  ,arr[right_child]) ;
				real_child = right_child ;
			}
		} else{

			if(arr[parent] > arr[left_child])
			{
				swap(arr[parent]  ,arr[left_child]) ;
	 			real_child = left_child ;
	 		}
		}


	} else if( left_child <= last_index ){
		//one child only
		swap(arr[parent]  ,arr[left_child]) ;
		real_child = left_child ;

	} else {
		//no child
		real_child = (2*(parent) + 1 );
	}

		parent = real_child ;

	} while(parent < last_index) ;


}

int main()
{


	add_to_heap(21) ;
	add_to_heap(45) ;
	add_to_heap(35) ;
	add_to_heap(450) ;
	add_to_heap(19) ;

	for(int i = 0 ; i <arr.size() ; i ++)
		cout << arr[i] <<" " ;
	cout <<endl ;

	remove_from_heap() ;

	for(int i = 0 ; i <arr.size() ; i ++)
		cout << arr[i] <<" " ;
	cout <<endl ;

	remove_from_heap() ;

	for(int i = 0 ; i <arr.size() ; i ++)
		cout << arr[i] <<" " ;
	cout <<endl ;

	remove_from_heap() ;

	for(int i = 0 ; i <arr.size() ; i ++)
		cout << arr[i] <<" " ;
	cout <<endl ;

	add_to_heap(9) ;
	for(int i = 0 ; i <arr.size() ; i ++)
		cout << arr[i] <<" " ;
	cout <<endl ;
	return 0;
}
