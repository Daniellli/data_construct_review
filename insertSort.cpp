#include "insertSort.h"
#define MaxSize 100

ElemType *data;
int main() {

	clock_t startTime,endTime;
	ElemType t,len=1;
//	initial(data,MaxSize);
	data = (ElemType*)malloc(sizeof(ElemType)*MaxSize);
	cout<<"input(-1 means action over):";
	cin>>t;
	//0 不存数据  0索引的数据是哨兵
	while(t!=-1) {
		data[len++]=t;
		cin>>t;
	}
//	cout<<"折半插入排序:\n";
//	startTime = clock();//计时开始
//	insert_middle_sort(data,len);
//	endTime = clock();//计时结束
	// CLOCKS_PER_SEC ==1000 endtime 记录的是毫秒数
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);
//	cout<<"shell sort :\n";
//	startTime = clock();//计时开始
//	ShellSort(data,len);
//	print(data,len);
//	endTime = clock();//计时结束
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;


//	cout<<"----------------------------------------\n";
//	startTime = clock();//计时开始
//	quickSort(data,1,len-1);
//	endTime = clock();//计时结束
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);


//	cout<<"---------冒泡sort-------------------------------\n";
//	startTime = clock();//计时开始
//	bubbleSort(data,len);
//	endTime = clock();//计时结束
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);
	cout<<"---------选择sort-------------------------------\n";
	startTime = clock();//计时开始
	choosingSort(data,len);
	endTime = clock();//计时结束
	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
	print(data,len);
	return 0;
}



//冒泡排序 n = len+1
void choosingSort(ElemType *A , int n) {
	int i ,j,min;
	ElemType tmp;
	for( i = 1; i<n-1; i++) {
		min = i;
		for(j = i+1; j<n; j++) {
			if(A[min]>A[j]) {
				min = j;
			}
		}
		if(min !=i) {
			tmp = A[min];
			A[min]=A[i];
			A[i]=tmp;
		}
	}

}

//冒泡排序
void bubbleSort(ElemType *A , int len) {
	int i,j;
	ElemType tmp;
	bool flag  ;
	for(i = 1; i<len; i++) {
		flag = false;
		for(j = len-1; j>0; j--) {
			if(A[j]<A[j-1]) {
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = true;
			}
		}
		if(flag == false) {
			break;
		}
	}
}

//快速排序
int partition(ElemType *A ,int low,int high) {
	int povit = A[low];
	while(low<high) {
		while(low<high&&A[high]>=povit) {
			high--;
		}
		A[low] = A[high];
		while(low<high&& A[low]<= povit) {
			low++;
		}
		A[high] = A[low];
	}
	A[low]=povit;
	return low;
}
void quickSort(ElemType *A ,int low,int high) {
	if(low<high) {
		int pos =partition(A,low,high);
		quickSort(A,low,pos-1);
		quickSort(A,pos+1,high);
	}

}

void ShellSort(ElemType *A , int len) {
	int i ,j,dk;
	for( dk = len/2 ; dk>=1; dk/=2) {//步长  从n/2开始 逐渐缩减到1
		for( i = dk+1; i<len; i++) {//所有分组一起遍历
			if(A[i] <A[i-dk]) {//如果前面有序的部分的最大的已经小于 当前这个元素的话就不要移动了
				A[0] = A[i];//哨兵
				//对该分组的当前元素找寻适合它的位置
				for( j = i-dk; j>0&&A[0] <A[j]; j-=dk) {
					A[j+dk] = A[j];
				}
				//放到找到的那个位置
				A[j+dk] = A[0];
			}
		}
	}
}

//len = length +1
void insert_sort(ElemType *A,int len) {
	int i,j;
	for(i  = 2; i<len; i++) { //遍历
		A[0] = A[i];//哨兵等于当前元素
		for(j = i -1 ; A[j]>A[0]; j--) { //找到 比当前元素小的元素
			A[j+1] = A[j];//后移
		}
		A[j+1] = A[0];
	}
}

//插入折半排序
void insert_middle_sort(ElemType *A , int len) {

	int i , j ,high,low,mid;
	for(i = 2; i<len; i++) {
		A[0] = A[i];
		low =1;
		high  = i-1;
		while(low<= high) {//找到可以插入数据的位置，high+1  或者low
			mid = (low+high)/2;
			if(A[0]<A[mid])
				high = mid-1;
			else
				low=mid+1;
		}

		for(j = i-1 ; j>=high+1; j--) {
			A[j+1] = A[j];
		}
		A[high+1] = A[0];
	}
}

void print(ElemType *A,int len) {

	for(int i = 1 ; i<len; i++) {
		cout<<A[i]<<"\t";
	}
	cout<<"\n";
}



//
//void initial(ElemType &*data ,int len) {
//	data = (ElemType*)malloc(sizeof(ElemType)*len);
//}
