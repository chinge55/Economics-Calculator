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
        EvaluateValue::to = *input_str;
        EvaluateValue::from = *(input_str+2);
        input_str = input_str + 4;
        while(*input_str!=',')
        {   

            string_stream1 << *input_str;
            input_str++;
        }     
        //std::cout << string_stream.str()<<std::endl;
        string_stream1 >> EvaluateValue::rate;  
        //string_stream.str("");    
        //std::cout<<*input_str<<std::endl;
        input_str++;
        std::cout<<*input_str<<std::endl;
        while(*input_str!=')')
        {
            string_stream2 << *input_str;
            input_str++;
        }
        string_stream2 >> EvaluateValue::time;
        string_stream2.str("");
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

        
    
}
void EvaluateValue::Printall()
{
    std::cout << EvaluateValue::to<<std::endl;
    std::cout << EvaluateValue::from<<std::endl;
    std::cout << EvaluateValue::rate<<std::endl;
    std::cout << EvaluateValue::time<<std::endl;
}
float EvaluateValue::Calculate()
{
    if(EvaluateValue::to =='P' || EvaluateValue::to =='p')
    {
        if(EvaluateValue::from == 'f' || EvaluateValue::from == 'F')
        {
            double denominator = 1+EvaluateValue::rate;
            denominator = pow(denominator,time);
            double numerator = 1;
            return numerator/denominator;
           
        }
        if(EvaluateValue::from == 'a' || EvaluateValue::from == 'A')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = val-1;
            double denominator = rate*val;
            return numerator/denominator;
        }

        if(EvaluateValue::from == 'g' || EvaluateValue::from == 'G')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = val -rate*time-1;
            double denominator = rate*rate *val;
            return numerator/denominator;
        }
    }
    if(EvaluateValue::to =='f' || EvaluateValue::to =='F')
    {
        if(EvaluateValue::from == 'p' || EvaluateValue::from == 'P')
        {
            double val = pow(1+EvaluateValue::rate,time);
            return val;
        }
        if(EvaluateValue::from == 'a' || EvaluateValue::from == 'A')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = val-1;
            double denominator = rate;
            return numerator/denominator;
        }
        if(EvaluateValue::from == 'g' || EvaluateValue::from == 'G')
        {
            std::cout<<"sorry"<<std::endl;
            return 0;
        }
    }

    if(EvaluateValue::to =='a' || EvaluateValue::to =='A')
    {
        if(EvaluateValue::from == 'p' || EvaluateValue::from == 'P')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = rate*val;
            double denominator = val-1;
            return numerator/denominator;

        }
        if(EvaluateValue::from == 'f' || EvaluateValue::from == 'F')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = rate;
            double denominator = val-1;
            return numerator/denominator;
        }

        if(EvaluateValue::from == 'g' || EvaluateValue::from == 'G')
        {
            double val = pow(1+EvaluateValue::rate,time);
            double numerator = val-rate*time-1;
            double denominator = rate*val-rate;
            return numerator/denominator;
        }
    }
    
}