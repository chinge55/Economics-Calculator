#include "EvaluateValue.h"
#include <iostream>
#include <sstream>
#include <math.h>

EvaluateValue::EvaluateValue(char* input_str)
{   
    try
    {
        std::stringstream string_stream1, string_stream2;
        input_str++;
        to = *input_str;
        from = *(input_str+2);
        input_str = input_str + 4;
        while(*input_str!=',')
        {   

            string_stream1 << *input_str;
            input_str++;
        }     
        //std::cout << string_stream.str()<<std::endl;
        string_stream1 >> rate;  
        //string_stream.str("");    
        //std::cout<<*input_str<<std::endl;
        input_str++;
       // std::cout<<*input_str<<std::endl;
        while(*input_str!=')')
        {
            string_stream2 << *input_str;
            input_str++;
        }
        string_stream2 >> time;
        string_stream2.str("");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

        
    
}
void EvaluateValue::Printall()
{
    std::cout <<to<<std::endl;
    std::cout <<from<<std::endl;
    std::cout <<rate<<std::endl;
    std::cout <<time<<std::endl;
}
float EvaluateValue::Calculate()
{
    if(to =='P' || to =='p')
    {
        if(from == 'f' || from == 'F')
        {
            double denominator = 1+rate;
            denominator = pow(denominator,time);
            double numerator = 1;
            return numerator/denominator;
           
        }
        if(from == 'a' || from == 'A')
        {
            double val = pow(1+rate,time);
            double numerator = val-1;
            double denominator = rate*val;
            return numerator/denominator;
        }

        if(from == 'g' || from == 'G')
        {
            double val = pow(1+rate,time);
            double numerator = val -rate*time-1;
            double denominator = rate*rate *val;
            return numerator/denominator;
        }
    }
    if(to =='f' || to =='F')
    {
        if(from == 'p' || from == 'P')
        {
            double val = pow(1+rate,time);
            return val;
        }
        if(from == 'a' || from == 'A')
        {
            double val = pow(1+rate,time);
            double numerator = val-1;
            double denominator = rate;
            return numerator/denominator;
        }
        if(from == 'g' || from == 'G')
        {
            std::cout<<"sorry"<<std::endl;
            return 0;
        }
    }

    if(to =='a' || to =='A')
    {
        if(from == 'p' || from == 'P')
        {
            double val = pow(1+rate,time);
            double numerator = rate*val;
            double denominator = val-1;
            return numerator/denominator;

        }
        if(from == 'f' || from == 'F')
        {
            double val = pow(1+rate,time);
            double numerator = rate;
            double denominator = val-1;
            return numerator/denominator;
        }

        if(from == 'g' || from == 'G')
        {
            double val = pow(1+rate,time);
            double numerator = val-rate*time-1;
            double denominator = rate*val-rate;
            return numerator/denominator;
        }
    }
    
}