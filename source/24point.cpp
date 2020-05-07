#include<iostream>
#include<vector>
#include<string>
using namespace std;
int tag[3];   //存放3个运算符的优先级，1表示+-，2表示* /
/* 根据tag标记的优先级判断是否加括号(从左向右计算),加输出加括号的表达式返回false，不加返回true*/
bool judge(string s)
{
    int t = 0;
    int m, n;
    if (tag[0] == 1 && tag[1] == 1 && tag[2] == 2 || tag[0] == 2
        && tag[1] == 1 && tag[2] == 2)
    { 
        m = s.rfind("*");
        n = s.rfind("/");
        t = m >n ? m : n;
        string temp = "(" + s.substr(0, t) + ")" + s.substr(t)+"  =24";
        cout << temp<< endl;
        return false;
    }
    else if (tag[0] == 1 && tag[1] == 2)
    {
        string temp = "(" + s.substr(0, 3) + ")" + s.substr(3) + "  =24";
        cout <<temp<< endl;
        return false;
    }
    return true;
}

/***********************对排列好的组合进行计算（递归）*******************************/
/********表示当前有t个数参与计算  ；num为当前t个数的计算结果（值）；当前的表达式*****/
void calculate(int t, int num, string s, vector<int> &arr)
{
    if (t == 4)
    {
        //这里是既不需要加括号而且结果为24输出，
        //当结果为24时，看从左到右计算是否满足计算优先级，利用judge()函数加括号，在judge函数中输出。
        if (num == 24 && judge(s))    
        {
            cout << s << "    =24 " << endl;
        }
        return;
    }
    if (t == 0)
    {
        calculate(t + 1, num + arr[t], to_string(arr[0]), arr);
        return;
    }
    for (int i = 0; i < 4; i++) 
    {
        if (i == 0) 
        {
            tag[t - 1] = 1;
            calculate(t + 1, num + arr[t], s + "+" + to_string(arr[t]),arr);
        }
        if (i == 1) 
        {
            tag[t - 1] = 1;
            if (num - arr[t] > 0)
            {
                calculate(t + 1, num - arr[t],s + "-" + to_string(arr[t]),arr);
            }
            //else     //如果return时返回上次一层t-1情况，for循环后面的情况没有考虑
            //{
            //    return;
            //}
        }
        if (i == 2) 
        {
            tag[t - 1] = 2;
            calculate(t + 1, num * arr[t], s + "*" + to_string(arr[t]),arr);
        }
        if (i == 3) 
        {
            tag[t - 1] = 2;
            if (num % arr[t] == 0) 
            {
                calculate(t + 1, num / arr[t], s + "/" + to_string(arr[t]),arr);
                    
            }
            //else 
            //{
            //    return;
            //}
        }
    }
}

void getOrder(size_t t, vector<int> &arr, int &cnt)       //进行排列组合,t从0开始,cnt计算有多少排列方式
{
    if (t >= arr.size())
    {
        calculate(0, 0, "",arr);                           //每一次排列好组合，对排列好的4个数用不同的方法计算。
        cnt++;
        return;
    }
    for (size_t i = t; i < arr.size(); i++)
    {
        if (i != t)
            swap(arr[i], arr[t]);
        getOrder(t + 1, arr, cnt);
        if (i != t)
            swap(arr[i], arr[t]);                      //表示交换之后再交换回来，要在原有的基础上（a,b,c,d）进行交换
    }
}

int main()               //测试
{
    static int cnt = 0;
    vector<int> arr; //存放4个数字
    
    cout << "**********************************24点游戏******************************" << endl;
    cout << "*******************请输入4个数字，并且4个数字均要在1到13之间**************" << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    arr.push_back(d);
    getOrder(0, arr, cnt);
    return 0;
}