#include <iostream>
#include "EvaluateValue.h"
#include <sstream>
using namespace std;

int main()
{
    while(1)
    {
        char input_str[100];
        cout << "enter the the formula in the form:"<<endl;
        cout << "(<to>/<from>,rate,time)"<<endl;
        cin >> input_str;
        if(*input_str!='(')
            break;
        EvaluateValue *e = new EvaluateValue(input_str);
        //e->Printall();
        cout << e->Calculate()<<endl;
    }
        return 0;
}