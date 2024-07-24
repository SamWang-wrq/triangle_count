#include "./include/geo.h"
#include "./include/Triangle.h"
#include "./include/Shape.h"
#include "./include/File.h"
#include "./include/tools.h"
//#define get(vector<Point> * temp){return Triangle(temp[0],temp[1],temp[2])}

std::map<int, int> hashmap; // 创建一个空的map，键类型为int，值类型为std::string


num m, n;

int main() {
	//cout << line.Print();
	//cout << L2S(&line);
	Point p = Point(1, 2);
	cout << p.Print();

	cout << "请输入横向个数m,纵向个数n";
	cin >> m >> n;
	int lobalm = m;
	int lobaln = n;
	//TODO -- 所有点的全集
	vector<Point*> U_p;//==>arr
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			Point* temp = (Point*)malloc(sizeof(p));
			*temp = Point(m, n);
			U_p.push_back(temp);
		}
	}

	//检查U_p;
	for (auto iter = U_p.begin(); iter != U_p.end(); iter++) {
		cout <<(Point*) iter->Print() << endl;
	}

	//cout << U_p[0].pos_x <<endl;
	system("pause");

	//TODO -- 获得所有点能组成的三角形
	vector<int> temp_index;//==>a
	vector<Triangle> U_t;
	m = 3;//取3个点
	n = U_p.size();
	
	{
	for (int i = 0; i < m; i++)//第一种组合，a[0]=1,a[1]=2,...a[m-1]=m;
	{
		temp_index.push_back(i + 1);
	}

	for (int j = m; temp_index[0] <= (n - m + 1);)//当组合为最后一组时，循环结束；即a[0]=n-m+1,...,a[m-1]=n;j用来判断进位，以及进位之后的调整
	{

		for (; temp_index[m - 1] <= n; temp_index[m - 1]++)//最后一位不断递增，直到达到最大值，产生进位
		{

			U_t.push_back(
				Triangle(&U_p[temp_index[0] - 1], &U_p[temp_index[1] - 1], &U_p[temp_index[2] - 1])
			);

		}

		for (j = m - 2; j >= 0; j--)//判断a[1]--a[m-2]是否有进位 如果 a[m-1]>n 产生进位
		{
			temp_index[j]++;
			if (temp_index[j] <= (j + n - m + 1))//a[j]不进位,那么a[j-1]也不进位，结束继续判断
			{
				break;
			}
		}

		for (j++; j > 0 && j < m; j++)//调整，使得a[index-1],a[index],a[index]顺序排列，其中a[index]产生进位
		{
			temp_index[j] = temp_index[j - 1] + 1;
		}
	}
}
//U_t 为所欲符合的三角形，筛选出面积为0.5的
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
	//获取所有三角形间的排列////////////////////////////////////////////////////
	m = 12;//取12个三角形///////////////////////////////////////////////////////
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
		for (int i = 0; i < m; i++)//第一种组合，a[0]=1,a[1]=2,...a[m-1]=m;
		{
			tri_temp_index.push_back(i + 1);
		}

		for (int j = m; tri_temp_index[0] <= (n - m + 1);)//当组合为最后一组时，循环结束；即a[0]=n-m+1,...,a[m-1]=n;j用来判断进位，以及进位之后的调整
		{
			vector<Triangle>* cuts = (vector < Triangle> *)malloc(sizeof(cuts_module));
			cuts->empty();
			for (; tri_temp_index[m - 1] <= n; tri_temp_index[m - 1]++)//最后一位不断递增，直到达到最大值，产生进位
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
			for (j = m - 2; j >= 0; j--)//判断a[1]--a[m-2]是否有进位 如果 a[m-1]>n 产生进位
			{
				tri_temp_index[j]++;
				if (tri_temp_index[j] <= (j + n - m + 1))//a[j]不进位,那么a[j-1]也不进位，结束继续判断
				{
					break;
				}
			}

			for (j++; j > 0 && j < m; j++)//调整，使得a[index-1],a[index],a[index]顺序排列，其中a[index]产生进位
			{
				tri_temp_index[j] = tri_temp_index[j - 1] + 1;
			}
		}
	}
	//准备把每个一条边分为它所有的最细边
	cout << "所有三角型组" << ans_U.size();
	//cout << "所有三角型组" << ans_U[0][0].first->pos_x;
	//cout << "所有三角型组" << ans_U[0][1].first->pos_x;
	//cout << "所有三角型组" << ans_U[0][2].first->pos_x;
	vector<vector<Triangle>*> ans;
	/*
	for (vector<vector<Triangle>*>::iterator iter = ans_U.begin(); iter != ans_U.end(); iter++)
	{
		hashmap.empty();
		bool end = true;
		
		for (auto& iter2 = ittr; iter2 != ittr->end(); iter++)
		{
			//填充hanmap
			iter2.hash();
			

		}
		//TODO 判断hash结果是否符合要求；
		for (const auto& pair :hashmap) {
			//std::cout << "键: " << pair.first << ", 值: " << pair.second << std::endl;
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


	fstream out("C:\\Users\\wrqwr\\工作区\\triangle_count\\test\\test-debug.txt", fstream::out);
	if (out.is_open())
	{//输出结果三角形等
		cout<<lobalm<<" "<<lobaln<<" "
		for (vector<vector<Triangle>*>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
			cout << iter<<" ";
		}




		out.close();
	}

	*/

	return 0;
}
