#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"inc.h"


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
        }
    }
}
