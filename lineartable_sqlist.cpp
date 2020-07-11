#include"lineartable_sqlist.h"
SeqList mylist;


//������
int main() {
	choose_menu();
//	printf("maxlength = %d",get_list_max_length(mylist));
//	printf("current length = %d",get_list_length(mylist));
	return 0;
}


//�ҵ���С������
int find_miss_min(SeqList list) {

	if(is_empty(list))
		return -1;

	int i;
	ElemType *t = (ElemType*)malloc(sizeof(ElemType)*list.length);
	memset(t,0,sizeof(ElemType)*list.length);

	for(i = 0 ; i<list.length; i++) {
		if(list.data[i]>0&& list.data[i]<=list.length) {
			t[list.data[i]-1]++;
		}
	}

	for(i = 0; i<list.length; i++) {
		if(t[i]==0) {
			break;
		}
	}
	return i+1;
}
//��Ԫ��
bool find_main_elem(SeqList a,ElemType &e) {

	if(is_empty(a))
		return false;


	int i,count=1,m = a.data[0];
	for(i=1; i<a.length; i++) {
		if(a.data[i]==m) {
			count++;
		} else {
			if(count==0) {
				m=a.data[i];
				count=1;
			} else {
				count--;
			}
		}
	}

	if(count>0)
		for(i =count =0; i<a.length; i++)
			if(a.data[i]==m)
				count++;
	if(count>a.length/2) {
		e= m;
	} else {
		e=-1;
	}
	return true;
}
//����˳���a��b ����λ��  ����e����  better
bool M_Search(SeqList a,SeqList b ,ElemType &e) {
	if(is_empty(a)||is_empty(b)) {
		cout<<"please init firstly\n";
		return false;
	}
	int s1 = 0,d1 = a.length-1,s2 = 0,d2 = b.length-1,m2,m1 ;
	while(s1!= d1 || s2 != d2 ) {
		m1 =(s1 +d1)/2;
		m2 = (s2+d2)/2;

		if(a.data[m1]==b.data[m2]) {
			e = a.data[m1];
			return true;
		}
		//��� 2  ��
		//���� a ��ǰm1 ��
		//��������b��m2�������
		if(a.data[m1] < b.data[m2]) {
			//�ж�aʣ����жϵĸ���Ϊ��������ż��
			if((s1+d1)%2==0) {//ż��
				s1 = m1;//����m1
				d2 = m2;//����b m2���������Ԫ��
			} else {
				s1 = m1+1;
				d2 = m2;
			}
			//���3 ��
			//����a�ϴ��һ�� ͬʱ���� b�н�С��һ��
		} else {
			//�ж�bʣ����жϵĸ���Ϊ��������ż��
			if((s2+d2)%2 == 0) {
				s2 = m2;
				d1 = m1;
			} else {
				s2=m2+1;
				d1=m1;
			}
		}
	}

//whileû�з���
//��ʾû���ҵ����е���λ��
//ѭ������  ��ʾ s1 == d1  and s2 ==d2
	//����ʣ�µ��������ֲ�����λ�� ֻ���ж�ֵ��С����Ϊ��λ������
	cout<<"a.data[s1] = "<<a.data[s1];
	cout<<"\nb.data[s2] = "<<b.data[s2]<<"\n";
	e = a.data[s1]<b.data[s2]?a.data[s1]:b.data[s2];
	return true;;
}
//�ҵ� list_a�� list_bһ�����λ��  ����e����
bool find_middle_number(SeqList list_a,SeqList list_b ,ElemType &e) {

	if(is_empty(list_a) || is_empty(list_b)) {
		return NULL;
	}
	int mid_index = (list_a.length+list_b.length)/2;
	int mid_value =0;
	int i=0,j=0,k=0;

	while(i<list_a.length&&j<list_b.length) {
		if(list_a.data[i]<list_b.data[j]) {

			mid_value = list_a.data[i++];
		} else {

			mid_value = list_b.data[j++];

		}
		k++;
		//�ҵ���λ��
		if(k== mid_index) {
			e =mid_value;
			return true;
		}

	}


	while(i<list_a.length) {
		i++;
		mid_value = list_a.data[i];
		k++;
		//�ҵ���λ��
		if(k== mid_index) {
			e =mid_value;
			return true;
		}
	}
	while(j<list_b.length) {
		j++;
		mid_value = list_b.data[j];
		k++;
		if(is_mid(k,mid_index )) {
			e = mid_value;
			return true;
		}
	}

	return true;
}

bool is_mid(int now_index,int want_index ) {
	//�ҵ���λ��
	return now_index== want_index;
}

//���������ƶ�spaceλ
bool move_left(SeqList &mylist ,int space) {
	if(is_empty(mylist)) {
		return NULL;
	}
	reverse_list_common(mylist,0,mylist.length-1);
	print_list(mylist);
	reverse_list_common(mylist,0,mylist.length-space-1);
	print_list(mylist);
	reverse_list_common(mylist,mylist.length-space,mylist.length-1);
	print_list(mylist);
	return true;
}

//���� mylist �е�  from  ~to ������
bool reverse_list_common(SeqList &mylist ,int from ,int to) {
	for( int i = 0 ; i<(to-from +1)/2; i++) {
		ElemType tmp = mylist.data[from+i];
		mylist.data[from+i] = mylist.data[to-i];
		mylist.data[to-i] = tmp;
	}
	return true;
}

//����Ԫ��e���ҵ��Ļ�����Ԫ�ؽ���λ�ã�û�ҵ��Ͳ��벢ʹ��˳�������
//����˳���
bool find_exchange_insert(SeqList &mylist ,ElemType e) {
	if(is_empty(mylist))
		return NULL;

	int low = 0 ,high = mylist.length-1,mid;

	while(low<=high) {
		mid = (high+low)/2;
		if(mylist.data[mid]==e) { //�ҵ���
			break;
		} else if(mylist.data[mid] >e ) {
			high =mid-1;
		} else {
			low=mid+1;
		}
	}

	if(mylist.data[mid]==e && mid!=mylist.length-1) { //��������һ���Ͳ��ý�����
		int t = mylist.data[mid];
		mylist.data[mid] = mylist.data[mid+1];
		mylist.data[mid+1] = t;
	}

	//û�ҵ�  ��Ҫ����Ԫ��  �жϵ�ǰ����ռ��Ƿ��㹻
	if(mylist.length==mylist.max) {
		enlarge_list(mylist);
	}

	if(low>high) {
		int i ;
		for(i= mylist.length-1; i>high; i--) {
			mylist.data[i+1] = mylist.data[i];
		}
		mylist.data[i+1] = e;
		mylist.length++;
	}
	return true;
}
/* ��˳����0~n  �� m~���  ����λ��*/
bool reverse_list_from_ab_to_ba(SeqList &mylist,int n,int m) {
	if(m+n != mylist.length) {
		cout<<"��������\n";
		return false;
	}

	int i ,j;
	ElemType tmp;

	for(i = 0 ; i<mylist.length/2; i++) {
		tmp =  mylist.data[i];
		mylist.data[i] = mylist.data[mylist.length-i-1] ;
		mylist.data[mylist.length-i-1]  = tmp;
	}

//�ֱ𽻻�ǰ�������Ӵ�
	for(j=0; j<m/2; j++) {
		tmp = mylist.data[j] ;
		mylist.data[j]=mylist.data[m-1-j];
		mylist.data[m-1-j] = tmp;
	}

	for(j=0; j<n/2; j++) {
		tmp = mylist.data[m+j] ;
		mylist.data[j+m]=mylist.data[m+n-1-j];
		mylist.data[m+n-1-j] = tmp;
	}

}

/*�ϲ����� ���� ˳���*/
SeqList emerge_list(SeqList list_a,SeqList list_b) {
	if(is_empty(list_a) || is_empty(list_b) ) {
		cout<<"����Ϊ��\n";
		return SEQ_NULL;
	}
	//��ʼ���ṹ˳���
	SeqList tmp;
	tmp.data=(int*)malloc(sizeof(int)*(list_a.length+list_b.length));
	tmp.max = list_a.length+list_b.length;
	tmp.length=0;

	int i=0,j=0;
	while(i<list_a.length&&j<list_b.length) {
		if(list_a.data[i] < list_b.data[j]) {
			tmp.data[tmp.length++] = list_a.data[i++];
		} else {
			tmp.data[tmp.length++] = list_b.data[j++];
		}
	}
	//�ֱ��ж��»����Ǹ�˳�����˳��û�ӽ���
	if(i<list_a.length) {
		while(i<list_a.length) {
			tmp.data[tmp.length++] = list_a.data[i++];
		}
	}

	if(j<list_b.length) {
		while(j<list_b.length) {
			tmp.data[tmp.length++] = list_b.data[j++];
		}
	}

	return tmp;
}

//ɾ���ظ���ֵʹ������ظ�
int  delete_list_by_repeat(SeqList &mylist) {
	int i,j,res;
	for( i =0,j=1; j<mylist.length; j++) {
		if(mylist.data[j]!=mylist.data[i]) {
			mylist.data[++i] = mylist.data[j];
		}
	}
	res = mylist.length-i-1;
	mylist.length=i+1;
	return  res;
}


//ɾ��ֵ��[a��b] ֮�����������
int  delete_list_by_range(SeqList &mylist,ElemType a,ElemType b) {
	int i ,k=0;
	if(a>b) {
		cout<<"����������\n";
		return -1;
	}

	if(is_empty(mylist)) {
		cout<<"���ȳ�ʼ��\n";
		return -1;
	}

	for(i=0; i<mylist.length; i++) {
		if(mylist.data[i]>=a&&mylist.data[i]<=b) {
			k++;
		} else {
			mylist.data[i-k] =mylist.data[i];
		}
	}
	mylist.length-=k;
	return k;
}

//������˳��
int  delete_list_value_better_too(SeqList &mylist,ElemType e) {
	int i,k=0;

	while(i<mylist.length) {
		if(mylist.data[i]==e) {
			k++;
		} else {
			mylist.data[i-k]=mylist.data[i];
		}
		i++;
	}
	mylist.length-=k;
	return k;
}

//������˳��
int  delete_list_value_better(SeqList &mylist,ElemType e) {
	int res  = 0,i,k=0;
	//�п�
	if(is_empty(mylist)) {
		cout<<"�ձ����ȳ�ʼ������\n";
		return false;
	}

	for( i =0; i<mylist.length; i++) {
		if(mylist.data[i]!=e) {
			mylist.data[k++]=mylist.data[i];
		}
	}
	//k�����ʵ��ɾ����������1
	res = mylist.length-k;//�ܵ�ɾ���ĸ��� n-a+1
//	cout<<"mylist.length:"<<mylist.length;
//	cout<<"\nk:"<<k;
//	cout<<"\nres :"<<res<<"\n";

	mylist.length=k;//ɾ��������鳤��
	return res;
}

//ɾ������ֵΪe������
int delete_list_value(SeqList &mylist,ElemType e) {
	int res  = 0,i;

	if(is_empty(mylist)) {
		cout<<"�ձ����ȳ�ʼ������\n";
		return false;
	}

	for( i =0; i<mylist.length; i++) {
		if(mylist.data[i]==e) {
			//ɾ��i
			mylist.data[i]= mylist.data[mylist.length-1];//�����һ�����ݸ��ǵ�i������
			mylist.length--;//����-1
			i--;//���¼����������Ƿ���e
			res++;
		}
	}
	return res;
}

//Ԫ������
bool reverse_list(SeqList &mylist) {
	if(is_empty(mylist)) {
		return false;
	}
	ElemType t ;
	for(int i =0; i<mylist.length/2; i++) {
//		swap(mylist.data[i],mylist.data[mylist.length-1-i]);
		t=mylist.data[i];
		mylist.data[i] = mylist.data[mylist.length-1-i];
		mylist.data[mylist.length-1-i] = t;
	}
	return true;
}

//�п�
bool is_empty(SeqList mylist) {
	if(mylist.data==0 ||mylist.length==0) {
		return true;
	}
	return false;
}

//��ʼ�� ����������

SeqList initList() {
	SeqList mylist;
	int x;

	mylist.data = (int*)malloc(sizeof(int)*MaxSize);
	mylist.max=MaxSize;
	mylist.length=0;//��ǰ����
	//��������
	printf("�����룺\n");
	scanf("%d",&x);
	while(x!=999) { //˳�������ı�־
		if(mylist.length==mylist.max)
			enlarge_list(mylist);//��������
		mylist.data[mylist.length]=x;
		mylist.length++;
		scanf("%d",&x);

	}
	return  mylist;
}

//���
void print_list(SeqList t) {

	for(int i = 0 ; i<t.length; i++) {
		printf("%d \t",t.data[i]);
	}
	printf("\n");

}

//��ȡ���鵱ǰ����
int get_list_length(SeqList list) {
	return list.length;
}


//��ȡ��������
int get_list_max_length(SeqList list) {
	return list.max;
}


//��iλ�ò���e
bool insert_list(SeqList &mylist,int i,ElemType e) {

	//�����û����ݴ�1��ʼ  ���ڴ洢���������ݴ�1��ʼ
	//�ж��û�Ҫ�����λ���Ƿ�С��1
	//���ߴ��ڵ�ǰ����ĳ���  ���鳤�ȴ�0��ʼ ����Ҫ��1
	if(i<1|| i>mylist.length+1) {
		return false;
	}

	//����ռ����� ��������
	if(mylist.length==mylist.max) {
		enlarge_list(mylist);
	}

	//i~mylist.length�����������ƶ�һ�� iλ�þͿճ�����
	for(int j =mylist.length; j>=i; j--) {
		mylist.data[j]=mylist.data[j-1];
	}

	mylist.data[i-1]=e;
	mylist.length++;
	return true;
}



//�޸�iλ�õ�����  �޸ĳ�e
bool update_list(SeqList &mylist,int i,ElemType e) {

	//�����û����ݴ�1��ʼ  ���ڴ洢���������ݴ�1��ʼ
	//�ж��û�Ҫ�����λ���Ƿ�С��1
	//���ߴ��ڵ�ǰ����ĳ���  ���鳤�ȴ�0��ʼ ����Ҫ��1
	if(i<1|| i>mylist.length+1) {
		return false;
	}

	mylist.data[i-1]=e;
	return true;
}

//ɾ������  ����e����
bool delete_list_elem(SeqList &mylist ,int i,ElemType &e) {
	if(mylist.data==0&&mylist.length==0&&mylist.max==0)
		return false;
	if(i<1 || i>mylist.length)
		return false;

	e = mylist.data[i-1];//ʵ�ʴ洢���û��Ӵ��������ݲ�1
	for(int j = i-1; j<mylist.length-1; j++) {
		mylist.data[j]=mylist.data[j+1];
	}
	mylist.length--;
	return true;
}


int print_menu() {
	int input;
	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cout<<"��ʼ�����ݱ�������:0 \n";
	cout<<"�������������:1 \n";
	cout<<"��������������:2 \n";
	cout<<"ɾ������������:3 \n";
	cout<<"�޸�����������:4 \n";
	cout<<"��������������:6 \n";
	cout<<"ɾ����Сֵ������:7 \n";
	cout<<"˳�������������:8 \n";
	cout<<"ɾ��˳����е�ĳ��ָ�����ݵ�����������:9 \n";
	cout<<"ɾ��ָ����Χ������������:10 \n";
	cout<<"ɾ���ظ�������ʹ˳����ظ�������:11 \n";
	cout<<"�ϲ�����˳���������:12 \n";
	cout<<"����ǰ�������Ӵ���p18 test8��������:13 \n";
	cout<<"p18 test 9  ������ 14 \n";
	cout<<"p18 test 10 ������ 15 \n";
	cout<<"������˳������λ�� ������ 16 \n";
	cout<<"���������� 17 \n";
	cout<<"�ҵ���λ��better than 16 ������ 18 \n";
	cout<<"��Ԫ�� ������ 19 \n";
	cout<<"��С������������ 20\n";


	cout<<"�˳�������:5 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


//��������   -1��ʾû�ҵ�
int locate_elem(SeqList mylist ,ElemType e) {

	for(int i = 0 ; i<mylist.length; i++) {
		if(mylist.data[i]==e) {
			return i;
		}
	}
	return -1;
}

//ɾ����СԪ��
bool delete_list_min(SeqList &mylist,ElemType &e) {
	if(is_empty(mylist)) {
		cout<<"˳���Ϊ��\n";
		return false;
	}

	int i,index = 0;
	ElemType t = mylist.data[index];//�����һ����С

	for(i = 1 ; i<mylist.length; i++) {
		if(mylist.data[i]<t) {
			index=i;
			t= mylist.data[i];
		}
	}

	e = t;//����ɾ����Ԫ��
	if(i-1 != index) {
		//�ж���Сֵ�Ƿ������һ�� ,
		//������һ���Ͳ��������һ��Ԫ���滻Ҫɾ������Сֵ��
		mylist.data[index] =  mylist.data[mylist.length-1];
	}

	mylist.length--;
	return true;
}




void choose_menu() {
	int user_input,t1,t2,res;
	SeqList list_b,list_c;
	user_input=print_menu();
	while(user_input!=5) {
		switch(user_input) {
			case 0:
				mylist = initList();
				break;
			case 1:
				print_list(mylist);
				break;
			case 2://��������
				if(mylist.data==0 &&mylist.max==0) {
					cout<<"���ȳ�ʼ������\n";
				} else {
					cout<<"������Ҫ�����λ��:";
					cin>>t1;
					cout<<"������Ҫ���������:";
					cin>>t2;
					if(insert_list(mylist,t1,t2))cout<<"����ɹ�\n";
					else cout<<"����ʧ��\n";
				}

				break;
			case 3:
				//ɾ��t1λ�õ�Ԫ�� ����ɾ����������t2���ػ���
				cout<<"������Ҫɾ����λ��:";
				cin>>t1;
				delete_list_elem(mylist,t1,t2);
				cout<<"ɾ����"<<t2<<"\n";
				break;
			case 4:
				if(mylist.data==0 && mylist.max==0) {
					cout<<"���ȳ�ʼ������\n";
				} else {
					cout<<"������Ҫ�޸ĵ�λ��:";
					cin>>t1;
					cout<<"������Ҫ�޸ĳ�ʲô����:";
					cin>>t2;
					if(update_list(mylist,t1,t2))cout<<"�޸ĳɹ�\n";
					else cout<<"�޸�ʧ��\n";
				}


				break;
			case 6:
				cout<<"������Ҫ���ҵ�����:";
				cin>>t2;
				t1 = locate_elem(mylist,t2);
				if(t1==-1)cout<<"δ�ҵ���\n";
				else cout<<"λ��Ϊ��"<<t1<<"\n";
				break;
			case 7:
				if(delete_list_min(mylist,t2)) {
					cout<<"ɾ���ɹ�,ɾ����Ԫ��Ϊ"<<t2<<"\n";
				} else
					cout<<"ɾ��ʧ��\n";
				break;
			case 8:
				if(reverse_list(mylist)) {
					cout<<"���óɹ�\n";
				} else
					cout<<"����ʧ��\n";

				break;
			case 9:
				cout<<"������Ҫɾ�������ݣ�";
				cin>>t2;
				t1 = delete_list_value_better_too(mylist,t2);//����ɾ���ĸ���
				cout<<"��ɾ����"<<t1<<"������\n";
				break;
			case 10:
				cout<<"������������:";
				cin>>t1;
				cout<<"������������:";
				cin>>t2;

				cout<<"��ɾ��"<<delete_list_by_range(mylist,t1,t2)<<"��Ԫ��\n";

				break;
			case 11:
				if(is_empty(mylist)) {
					cout<<"���ȳ�ʼ��\n";
					break;
				}
				sort(mylist.data,mylist.data+mylist.length);
				cout<<"��ɾ����"<<delete_list_by_repeat(mylist)<<"��\n";
				break;
			case 12:
				cout<<"��ʼ���ڶ���˳���\n";
				list_b = initList ();
				cout<<"�������˳���Ϊ��\n";
				print_list(list_b);
				sort(mylist.data,mylist.data+mylist.length);
				sort(list_b.data,list_b.data+list_b.length);
				list_c = emerge_list(mylist,list_b);
				cout<<"�ϲ���Ϊ��\n";
				print_list(list_c);
				break;
			case 13:
				cout<<"�����һ���Ӵ��ĳ���m:";
				cin>>t1;
				cout<<"����ڶ����Ӵ��ĳ���n:";
				cin>>t2;
				reverse_list_from_ab_to_ba(mylist,t1,t2);
				break;
			case 14:
				sort(mylist.data,mylist.data+mylist.length);//����
				cout<<"������Ҫ����������:\n";
				cin>>t1;
				if(find_exchange_insert(mylist,t1)) {
					cout<<"�����ɹ�\n";
				} else {
					cout<<"����ʧ��\n";
				}
				break;
			case 15:
				cout<<"������Ҫ���Ƶ�λ��:\n";
				cin>>t1;
				if(	move_left(mylist,t1)) {
					cout<<"�����ɹ�\n";
				} else {
					cout<<"����ʧ��\n";
				}
				break;
			case 16:
				cout<<"��ʼ���ڶ���˳���\n";
				list_b = initList ();
				cout<<"�������˳���Ϊ��\n";
				print_list(list_b);
				sort(mylist.data,mylist.data+mylist.length);
				sort(list_b.data,list_b.data+list_b.length);
				if(find_middle_number(mylist,list_b,t2)) {
					cout<<"middle number equals to "<<t2<<"\n";
				} else {
					cout<<"failed !\n";
				}
				break;
			case 17:
				sort(mylist.data,mylist.data+mylist.length);
				break;
			case 18:
				cout<<"��ʼ���ڶ���˳���\n";
				list_b = initList ();
				cout<<"�������˳���Ϊ��\n";
				print_list(list_b);
				sort(mylist.data,mylist.data+mylist.length);
				sort(list_b.data,list_b.data+list_b.length);
				if(M_Search(mylist,list_b,t2)) {
					cout<<"middle number equals to "<<t2<<"\n";
				} else {
					cout<<"failed !\n";
				}
				break;

			case 19:
				find_main_elem(mylist,t2);
				cout<<"��Ԫ��Ϊ"<<t2<<"\n";
				break;
			case 20:
				cout<<"��С������Ϊ"<<find_miss_min(mylist)<<"\n";
				break;

		}
		user_input=print_menu();
	}

}


/*
��������
*/
void enlarge_list(SeqList &list) {
	SeqList tmp;
	tmp.data = list.data;
	list.data = (int*)malloc(sizeof(int)*list.max*2);//����һ�� ��С
	list.max=list.max*2;
	//��������
	for(int i =0; i<list.length; i++) {
		list.data[i]=tmp.data[i];
	}
	free(tmp.data);
}
