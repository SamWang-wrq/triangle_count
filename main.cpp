#include "./include/geo.h"
#include "./include/Triangle.h"
#include "./include/Shape.h"
#include "./include/File.h"
#include "./include/tools.h"
//#define get(vector<Point> * temp){return Triangle(temp[0],temp[1],temp[2])}

std::map<int, int> hashmap; // ����һ���յ�map��������Ϊint��ֵ����Ϊstd::string


num m, n;

int main() {
	//cout << line.Print();
	//cout << L2S(&line);
	Point p = Point(1, 2);
	cout << p.Print();

	cout << "������������m,�������n";
	cin >> m >> n;
	int lobalm = m;
	int lobaln = n;
	//TODO -- ���е��ȫ��
	vector<Point*> U_p;//==>arr
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			Point* temp = (Point*)malloc(sizeof(p));
			*temp = Point(m, n);
			U_p.push_back(temp);
		}
	}

	//���U_p;
	for (auto iter = U_p.begin(); iter != U_p.end(); iter++) {
		cout <<(Point*) iter->Print() << endl;
	}

	//cout << U_p[0].pos_x <<endl;
	system("pause");

	//TODO -- ������е�����ɵ�������
	vector<int> temp_index;//==>a
	vector<Triangle> U_t;
	m = 3;//ȡ3����
	n = U_p.size();
	
	{
	for (int i = 0; i < m; i++)//��һ����ϣ�a[0]=1,a[1]=2,...a[m-1]=m;
	{
		temp_index.push_back(i + 1);
	}

	for (int j = m; temp_index[0] <= (n - m + 1);)//�����Ϊ���һ��ʱ��ѭ����������a[0]=n-m+1,...,a[m-1]=n;j�����жϽ�λ���Լ���λ֮��ĵ���
	{

		for (; temp_index[m - 1] <= n; temp_index[m - 1]++)//���һλ���ϵ�����ֱ���ﵽ���ֵ��������λ
		{

			U_t.push_back(
				Triangle(&U_p[temp_index[0] - 1], &U_p[temp_index[1] - 1], &U_p[temp_index[2] - 1])
			);

		}

		for (j = m - 2; j >= 0; j--)//�ж�a[1]--a[m-2]�Ƿ��н�λ ��� a[m-1]>n ������λ
		{
			temp_index[j]++;
			if (temp_index[j] <= (j + n - m + 1))//a[j]����λ,��ôa[j-1]Ҳ����λ�����������ж�
			{
				break;
			}
		}

		for (j++; j > 0 && j < m; j++)//������ʹ��a[index-1],a[index],a[index]˳�����У�����a[index]������λ
		{
			temp_index[j] = temp_index[j - 1] + 1;
		}
	}
}
//U_t Ϊ�������ϵ������Σ�ɸѡ�����Ϊ0.5��
	//cout << U_t.size();

	vector<Triangle> half;
	for (vector<Triangle>::iterator iter = U_t.begin(); iter != U_t.end(); iter++)
	{
		cout << iter->first->Print() << " " << iter->second->Print() << endl;//cout << "size good";
		cout << iter->Size();
		if (iter->Size()==1 ){
			//cout << "size good";
			half.push_back(*iter);
		}
	}

	system("pause");
	//��ȡ���������μ������////////////////////////////////////////////////////
	m = 12;//ȡ12��������///////////////////////////////////////////////////////
	n = half.size();

	vector<int> tri_temp_index;
	vector<vector<Triangle>*> ans_U;
	vector<Triangle> cuts_module = {
		/*
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//1
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//2
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//3
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//4
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//5
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//6
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//7
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//8
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//9
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//10
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//11
		Triangle(&Point(1,1),&Point(1,1),&Point(1,1)),//12
	*/
	
	};


	{
		for (int i = 0; i < m; i++)//��һ����ϣ�a[0]=1,a[1]=2,...a[m-1]=m;
		{
			tri_temp_index.push_back(i + 1);
		}

		for (int j = m; tri_temp_index[0] <= (n - m + 1);)//�����Ϊ���һ��ʱ��ѭ����������a[0]=n-m+1,...,a[m-1]=n;j�����жϽ�λ���Լ���λ֮��ĵ���
		{
			vector<Triangle>* cuts = (vector < Triangle> *)malloc(sizeof(cuts_module));
			cuts->empty();
			for (; tri_temp_index[m - 1] <= n; tri_temp_index[m - 1]++)//���һλ���ϵ�����ֱ���ﵽ���ֵ��������λ
			{
				//cuts.push_back(
				//	new vector<Triangle>(half[0])
				//);//\			U_t.push_back(
				//	Triangle(&U_p[temp_index[0] - 1], &U_p[temp_index[1] - 1], &U_p[temp_index[2] - 1])
				//);
				
				cuts->push_back(half[temp_index[0] - 1]);

				
			}
			ans_U.push_back(cuts);

			//////////////////////////////////////Sans_U.push_back(vector<Triangle> outArray(cuts));
			for (j = m - 2; j >= 0; j--)//�ж�a[1]--a[m-2]�Ƿ��н�λ ��� a[m-1]>n ������λ
			{
				tri_temp_index[j]++;
				if (tri_temp_index[j] <= (j + n - m + 1))//a[j]����λ,��ôa[j-1]Ҳ����λ�����������ж�
				{
					break;
				}
			}

			for (j++; j > 0 && j < m; j++)//������ʹ��a[index-1],a[index],a[index]˳�����У�����a[index]������λ
			{
				tri_temp_index[j] = tri_temp_index[j - 1] + 1;
			}
		}
	}
	//׼����ÿ��һ���߷�Ϊ�����е���ϸ��
	cout << "������������" << ans_U.size();
	//cout << "������������" << ans_U[0][0].first->pos_x;
	//cout << "������������" << ans_U[0][1].first->pos_x;
	//cout << "������������" << ans_U[0][2].first->pos_x;
	vector<vector<Triangle>*> ans;
	/*
	for (vector<vector<Triangle>*>::iterator iter = ans_U.begin(); iter != ans_U.end(); iter++)
	{
		hashmap.empty();
		bool end = true;
		
		for (auto& iter2 = ittr; iter2 != ittr->end(); iter++)
		{
			//���hanmap
			iter2.hash();
			

		}
		//TODO �ж�hash����Ƿ����Ҫ��
		for (const auto& pair :hashmap) {
			//std::cout << "��: " << pair.first << ", ֵ: " << pair.second << std::endl;
			int a = pair.first;
			int b = pair.second;
			


			if (!end) {
				break;
			}

			if (&& a != 1) {
				end = false;
				break;
			}
			else
			{
				if (b != 2) {

					end = false;
					break;
				}
			}
		}
		if (end) {
			ans.push_back(iter);

		}
	}


	fstream out("C:\\Users\\wrqwr\\������\\triangle_count\\test\\test-debug.txt", fstream::out);
	if (out.is_open())
	{//�����������ε�
		cout<<lobalm<<" "<<lobaln<<" "
		for (vector<vector<Triangle>*>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
			cout << iter<<" ";
		}




		out.close();
	}

	*/

	return 0;
}
