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
	//0 ��������  0�������������ڱ�
	while(t!=-1) {
		data[len++]=t;
		cin>>t;
	}
//	cout<<"�۰��������:\n";
//	startTime = clock();//��ʱ��ʼ
//	insert_middle_sort(data,len);
//	endTime = clock();//��ʱ����
	// CLOCKS_PER_SEC ==1000 endtime ��¼���Ǻ�����
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);
//	cout<<"shell sort :\n";
//	startTime = clock();//��ʱ��ʼ
//	ShellSort(data,len);
//	print(data,len);
//	endTime = clock();//��ʱ����
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;


//	cout<<"----------------------------------------\n";
//	startTime = clock();//��ʱ��ʼ
//	quickSort(data,1,len-1);
//	endTime = clock();//��ʱ����
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);


//	cout<<"---------ð��sort-------------------------------\n";
//	startTime = clock();//��ʱ��ʼ
//	bubbleSort(data,len);
//	endTime = clock();//��ʱ����
//	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
//	print(data,len);
	cout<<"---------ѡ��sort-------------------------------\n";
	startTime = clock();//��ʱ��ʼ
	choosingSort(data,len);
	endTime = clock();//��ʱ����
	cout << "The run time is: " <<(double)(endTime - startTime)/CLOCKS_PER_SEC  << "s" << endl;
	print(data,len);
	return 0;
}



//ð������ n = len+1
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

//ð������
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

//��������
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
	for( dk = len/2 ; dk>=1; dk/=2) {//����  ��n/2��ʼ ��������1
		for( i = dk+1; i<len; i++) {//���з���һ�����
			if(A[i] <A[i-dk]) {//���ǰ������Ĳ��ֵ������Ѿ�С�� ��ǰ���Ԫ�صĻ��Ͳ�Ҫ�ƶ���
				A[0] = A[i];//�ڱ�
				//�Ը÷���ĵ�ǰԪ����Ѱ�ʺ�����λ��
				for( j = i-dk; j>0&&A[0] <A[j]; j-=dk) {
					A[j+dk] = A[j];
				}
				//�ŵ��ҵ����Ǹ�λ��
				A[j+dk] = A[0];
			}
		}
	}
}

//len = length +1
void insert_sort(ElemType *A,int len) {
	int i,j;
	for(i  = 2; i<len; i++) { //����
		A[0] = A[i];//�ڱ����ڵ�ǰԪ��
		for(j = i -1 ; A[j]>A[0]; j--) { //�ҵ� �ȵ�ǰԪ��С��Ԫ��
			A[j+1] = A[j];//����
		}
		A[j+1] = A[0];
	}
}

//�����۰�����
void insert_middle_sort(ElemType *A , int len) {

	int i , j ,high,low,mid;
	for(i = 2; i<len; i++) {
		A[0] = A[i];
		low =1;
		high  = i-1;
		while(low<= high) {//�ҵ����Բ������ݵ�λ�ã�high+1  ����low
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
