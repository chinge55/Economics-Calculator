#include <iostream>
#include "EvaluateValue.h"
#include <sstream>
using namespace std;

int main()
{
    char input_str[100];
    cout << "enter the the formula in the form:"<<endl;
    cout << "(<to>/<from>,rate,time)"<<endl;
    cin >> input_str;
    EvaluateValue *e = new EvaluateValue(input_str);
    //e->Printall();
    cout << e->Calculate();
    return 0;
}