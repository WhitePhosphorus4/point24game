#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"inc.h"
int tag[3];



int main()
{
    static int cnt = 0;
    vector<int> arr; //存放4个数字
    
    cout << "*******************请输入4个数字，并且4个数字均要在1到13之间**************" << endl;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(cha(a)&&cha(b)&&cha(c)&&cha(d))
    {
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        arr.push_back(d);
        getOrder(0, arr, cnt);
        cout << "******************************输出完成，游戏结束********************************"<<endl;
    }
    else
    {
        cout << "******************************输入有误，游戏结束********************************"<<endl;
    }
    return 0;
}