#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include"inc.h"

bool isOk(string s)
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
