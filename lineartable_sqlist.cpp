#include"lineartable_sqlist.h"
SeqList mylist;


//主函数
int main() {
	choose_menu();
//	printf("maxlength = %d",get_list_max_length(mylist));
//	printf("current length = %d",get_list_length(mylist));
	return 0;
}


//找到最小正整数
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
//主元素
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
//搜索顺序表a和b 的中位数  并用e返回  better
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
		//情况 2  ：
		//舍弃 a 的前m1 个
		//并且舍弃b的m2后的数据
		if(a.data[m1] < b.data[m2]) {
			//判断a剩余待判断的个数为奇数还是偶数
			if((s1+d1)%2==0) {//偶数
				s1 = m1;//保留m1
				d2 = m2;//舍弃b m2往后的所有元素
			} else {
				s1 = m1+1;
				d2 = m2;
			}
			//情况3 ：
			//舍弃a较大的一半 同时舍弃 b中较小的一半
		} else {
			//判断b剩余待判断的个数为奇数还是偶数
			if((s2+d2)%2 == 0) {
				s2 = m2;
				d1 = m1;
			} else {
				s2=m2+1;
				d1=m1;
			}
		}
	}

//while没有返回
//表示没有找到共有的中位数
//循环结束  表示 s1 == d1  and s2 ==d2
	//现在剩下的是两个局部最中位数 只需判断值较小的作为中位数即可
	cout<<"a.data[s1] = "<<a.data[s1];
	cout<<"\nb.data[s2] = "<<b.data[s2]<<"\n";
	e = a.data[s1]<b.data[s2]?a.data[s1]:b.data[s2];
	return true;;
}
//找到 list_a和 list_b一起的中位数  并用e返回
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
		//找到中位数
		if(k== mid_index) {
			e =mid_value;
			return true;
		}

	}


	while(i<list_a.length) {
		i++;
		mid_value = list_a.data[i];
		k++;
		//找到中位数
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
	//找到中位数
	return now_index== want_index;
}

//将数组左移动space位
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

//逆置 mylist 中的  from  ~to 的数据
bool reverse_list_common(SeqList &mylist ,int from ,int to) {
	for( int i = 0 ; i<(to-from +1)/2; i++) {
		ElemType tmp = mylist.data[from+i];
		mylist.data[from+i] = mylist.data[to-i];
		mylist.data[to-i] = tmp;
	}
	return true;
}

//查找元素e，找到的话与后继元素交换位置，没找到就插入并使其顺序表有序
//有序顺序表
bool find_exchange_insert(SeqList &mylist ,ElemType e) {
	if(is_empty(mylist))
		return NULL;

	int low = 0 ,high = mylist.length-1,mid;

	while(low<=high) {
		mid = (high+low)/2;
		if(mylist.data[mid]==e) { //找到了
			break;
		} else if(mylist.data[mid] >e ) {
			high =mid-1;
		} else {
			low=mid+1;
		}
	}

	if(mylist.data[mid]==e && mid!=mylist.length-1) { //如果是最后一个就不用交换了
		int t = mylist.data[mid];
		mylist.data[mid] = mylist.data[mid+1];
		mylist.data[mid+1] = t;
	}

	//没找到  需要插入元素  判断当前数组空间是否足够
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
/* 将顺序表的0~n  和 m~最后  调换位置*/
bool reverse_list_from_ab_to_ba(SeqList &mylist,int n,int m) {
	if(m+n != mylist.length) {
		cout<<"输入有误\n";
		return false;
	}

	int i ,j;
	ElemType tmp;

	for(i = 0 ; i<mylist.length/2; i++) {
		tmp =  mylist.data[i];
		mylist.data[i] = mylist.data[mylist.length-i-1] ;
		mylist.data[mylist.length-i-1]  = tmp;
	}

//分别交换前后两个子串
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

/*合并两个 有序 顺序表*/
SeqList emerge_list(SeqList list_a,SeqList list_b) {
	if(is_empty(list_a) || is_empty(list_b) ) {
		cout<<"不能为空\n";
		return SEQ_NULL;
	}
	//初始化结构顺序表
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
	//分别判断下还有那个顺序表还有顺序没加进来
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

//删除重复的值使其均不重复
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


//删除值在[a，b] 之间的所有数据
int  delete_list_by_range(SeqList &mylist,ElemType a,ElemType b) {
	int i ,k=0;
	if(a>b) {
		cout<<"区间有问题\n";
		return -1;
	}

	if(is_empty(mylist)) {
		cout<<"请先初始化\n";
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

//不打乱顺序
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

//不打乱顺序
int  delete_list_value_better(SeqList &mylist,ElemType e) {
	int res  = 0,i,k=0;
	//判空
	if(is_empty(mylist)) {
		cout<<"空表，请先初始化数据\n";
		return false;
	}

	for( i =0; i<mylist.length; i++) {
		if(mylist.data[i]!=e) {
			mylist.data[k++]=mylist.data[i];
		}
	}
	//k最后会比实际删除的索引多1
	res = mylist.length-k;//总的删除的个数 n-a+1
//	cout<<"mylist.length:"<<mylist.length;
//	cout<<"\nk:"<<k;
//	cout<<"\nres :"<<res<<"\n";

	mylist.length=k;//删除后的数组长度
	return res;
}

//删除所有值为e的数据
int delete_list_value(SeqList &mylist,ElemType e) {
	int res  = 0,i;

	if(is_empty(mylist)) {
		cout<<"空表，请先初始化数据\n";
		return false;
	}

	for( i =0; i<mylist.length; i++) {
		if(mylist.data[i]==e) {
			//删除i
			mylist.data[i]= mylist.data[mylist.length-1];//将最后一个数据覆盖第i个数据
			mylist.length--;//长度-1
			i--;//重新检查这个数据是否是e
			res++;
		}
	}
	return res;
}

//元素逆置
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

//判空
bool is_empty(SeqList mylist) {
	if(mylist.data==0 ||mylist.length==0) {
		return true;
	}
	return false;
}

//初始化 并输入数组

SeqList initList() {
	SeqList mylist;
	int x;

	mylist.data = (int*)malloc(sizeof(int)*MaxSize);
	mylist.max=MaxSize;
	mylist.length=0;//当前长度
	//输入数据
	printf("请输入：\n");
	scanf("%d",&x);
	while(x!=999) { //顺序表结束的标志
		if(mylist.length==mylist.max)
			enlarge_list(mylist);//扩充数组
		mylist.data[mylist.length]=x;
		mylist.length++;
		scanf("%d",&x);

	}
	return  mylist;
}

//输出
void print_list(SeqList t) {

	for(int i = 0 ; i<t.length; i++) {
		printf("%d \t",t.data[i]);
	}
	printf("\n");

}

//获取数组当前长度
int get_list_length(SeqList list) {
	return list.length;
}


//获取数组容量
int get_list_max_length(SeqList list) {
	return list.max;
}


//在i位置插入e
bool insert_list(SeqList &mylist,int i,ElemType e) {

	//对于用户数据从1开始  对于存储的数组数据从1开始
	//判断用户要插入的位置是否小于1
	//或者大于当前数组的长度  数组长度从0开始 所以要加1
	if(i<1|| i>mylist.length+1) {
		return false;
	}

	//数组空间已满 扩大数组
	if(mylist.length==mylist.max) {
		enlarge_list(mylist);
	}

	//i~mylist.length个数据往后移动一个 i位置就空出来了
	for(int j =mylist.length; j>=i; j--) {
		mylist.data[j]=mylist.data[j-1];
	}

	mylist.data[i-1]=e;
	mylist.length++;
	return true;
}



//修改i位置的数据  修改成e
bool update_list(SeqList &mylist,int i,ElemType e) {

	//对于用户数据从1开始  对于存储的数组数据从1开始
	//判断用户要插入的位置是否小于1
	//或者大于当前数组的长度  数组长度从0开始 所以要加1
	if(i<1|| i>mylist.length+1) {
		return false;
	}

	mylist.data[i-1]=e;
	return true;
}

//删除数据  并用e返回
bool delete_list_elem(SeqList &mylist ,int i,ElemType &e) {
	if(mylist.data==0&&mylist.length==0&&mylist.max==0)
		return false;
	if(i<1 || i>mylist.length)
		return false;

	e = mylist.data[i-1];//实际存储和用户接触到的数据差1
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
	cout<<"初始化数据表请输入:0 \n";
	cout<<"输出数据请输入:1 \n";
	cout<<"插入数据请输入:2 \n";
	cout<<"删除数据请输入:3 \n";
	cout<<"修改数据请输入:4 \n";
	cout<<"查找数据请输入:6 \n";
	cout<<"删除最小值请输入:7 \n";
	cout<<"顺序表逆置请输入:8 \n";
	cout<<"删除顺序表中的某个指定数据的所有请输入:9 \n";
	cout<<"删除指定范围的数据请输入:10 \n";
	cout<<"删除重复的数据使顺序表不重复请输入:11 \n";
	cout<<"合并有序顺序表请输入:12 \n";
	cout<<"交换前后两个子串（p18 test8）请输入:13 \n";
	cout<<"p18 test 9  请输入 14 \n";
	cout<<"p18 test 10 请输入 15 \n";
	cout<<"找两个顺序表的中位数 请输入 16 \n";
	cout<<"排序请输入 17 \n";
	cout<<"找到中位数better than 16 请输入 18 \n";
	cout<<"主元素 请输入 19 \n";
	cout<<"最小正整数请输入 20\n";


	cout<<"退出请输入:5 \n";

	for(int i = 0 ; i<=30; i++)
		cout<<"##" ;
	cout<<"\n";
	cin>>input;
	return input;
}


//查找数据   -1表示没找到
int locate_elem(SeqList mylist ,ElemType e) {

	for(int i = 0 ; i<mylist.length; i++) {
		if(mylist.data[i]==e) {
			return i;
		}
	}
	return -1;
}

//删除最小元素
bool delete_list_min(SeqList &mylist,ElemType &e) {
	if(is_empty(mylist)) {
		cout<<"顺序表为空\n";
		return false;
	}

	int i,index = 0;
	ElemType t = mylist.data[index];//假设第一个最小

	for(i = 1 ; i<mylist.length; i++) {
		if(mylist.data[i]<t) {
			index=i;
			t= mylist.data[i];
		}
	}

	e = t;//返回删除的元素
	if(i-1 != index) {
		//判断最小值是否是最后一个 ,
		//如果最好一个就不用拿最后一个元素替换要删除的最小值了
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
			case 2://插入数据
				if(mylist.data==0 &&mylist.max==0) {
					cout<<"请先初始化数据\n";
				} else {
					cout<<"请输入要插入的位置:";
					cin>>t1;
					cout<<"请输入要插入的数据:";
					cin>>t2;
					if(insert_list(mylist,t1,t2))cout<<"插入成功\n";
					else cout<<"插入失败\n";
				}

				break;
			case 3:
				//删除t1位置的元素 并把删除的数据用t2返回回来
				cout<<"请输入要删除的位置:";
				cin>>t1;
				delete_list_elem(mylist,t1,t2);
				cout<<"删除了"<<t2<<"\n";
				break;
			case 4:
				if(mylist.data==0 && mylist.max==0) {
					cout<<"请先初始化数据\n";
				} else {
					cout<<"请输入要修改的位置:";
					cin>>t1;
					cout<<"请输入要修改成什么数据:";
					cin>>t2;
					if(update_list(mylist,t1,t2))cout<<"修改成功\n";
					else cout<<"修改失败\n";
				}


				break;
			case 6:
				cout<<"请输入要查找的数据:";
				cin>>t2;
				t1 = locate_elem(mylist,t2);
				if(t1==-1)cout<<"未找到！\n";
				else cout<<"位置为："<<t1<<"\n";
				break;
			case 7:
				if(delete_list_min(mylist,t2)) {
					cout<<"删除成功,删除的元素为"<<t2<<"\n";
				} else
					cout<<"删除失败\n";
				break;
			case 8:
				if(reverse_list(mylist)) {
					cout<<"逆置成功\n";
				} else
					cout<<"逆置失败\n";

				break;
			case 9:
				cout<<"请输入要删除的数据：";
				cin>>t2;
				t1 = delete_list_value_better_too(mylist,t2);//返回删除的个数
				cout<<"共删除了"<<t1<<"个数据\n";
				break;
			case 10:
				cout<<"请输入左区间:";
				cin>>t1;
				cout<<"请输入右区间:";
				cin>>t2;

				cout<<"共删除"<<delete_list_by_range(mylist,t1,t2)<<"个元素\n";

				break;
			case 11:
				if(is_empty(mylist)) {
					cout<<"请先初始化\n";
					break;
				}
				sort(mylist.data,mylist.data+mylist.length);
				cout<<"共删除了"<<delete_list_by_repeat(mylist)<<"个\n";
				break;
			case 12:
				cout<<"初始化第二个顺序表\n";
				list_b = initList ();
				cout<<"您输入的顺序表为：\n";
				print_list(list_b);
				sort(mylist.data,mylist.data+mylist.length);
				sort(list_b.data,list_b.data+list_b.length);
				list_c = emerge_list(mylist,list_b);
				cout<<"合并后为：\n";
				print_list(list_c);
				break;
			case 13:
				cout<<"输入第一个子串的长度m:";
				cin>>t1;
				cout<<"输入第二个子串的长度n:";
				cin>>t2;
				reverse_list_from_ab_to_ba(mylist,t1,t2);
				break;
			case 14:
				sort(mylist.data,mylist.data+mylist.length);//排序
				cout<<"请输入要操作的数据:\n";
				cin>>t1;
				if(find_exchange_insert(mylist,t1)) {
					cout<<"操作成功\n";
				} else {
					cout<<"操作失败\n";
				}
				break;
			case 15:
				cout<<"请输入要左移的位数:\n";
				cin>>t1;
				if(	move_left(mylist,t1)) {
					cout<<"操作成功\n";
				} else {
					cout<<"操作失败\n";
				}
				break;
			case 16:
				cout<<"初始化第二个顺序表\n";
				list_b = initList ();
				cout<<"您输入的顺序表为：\n";
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
				cout<<"初始化第二个顺序表\n";
				list_b = initList ();
				cout<<"您输入的顺序表为：\n";
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
				cout<<"主元素为"<<t2<<"\n";
				break;
			case 20:
				cout<<"最小正整数为"<<find_miss_min(mylist)<<"\n";
				break;

		}
		user_input=print_menu();
	}

}


/*
扩大数组
*/
void enlarge_list(SeqList &list) {
	SeqList tmp;
	tmp.data = list.data;
	list.data = (int*)malloc(sizeof(int)*list.max*2);//扩大一倍 大小
	list.max=list.max*2;
	//复制数据
	for(int i =0; i<list.length; i++) {
		list.data[i]=tmp.data[i];
	}
	free(tmp.data);
}
