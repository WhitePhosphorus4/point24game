#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"inc.h"

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
